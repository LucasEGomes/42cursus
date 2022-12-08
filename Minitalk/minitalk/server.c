#include "server.h"
#include "ft_write.h"
#include "ft_itoa.h"
#include "ft_strlen.h"
#include <stdlib.h>
#include <signal.h>

t_deque	g_signals;

int	print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (pid == NULL)
		return (1);
	ft_write(STDOUT_FILENO, pid, ft_strlen(pid));
	ft_write(STDOUT_FILENO, "\n", 1);
	free(pid);
	return (0);
}

int	failed_to_initialize_server(void)
{
	ft_write(STDOUT_FILENO, ERROR_FAILED_TO_ALLOCATE_MEMORY, 28);
	return (1);
}

void	initialize_communication_signal_mask(struct sigaction *signal_action)
{
	sigemptyset(&signal_action->sa_mask);
	sigaddset(&signal_action->sa_mask, SIGUSR1);
	sigaddset(&signal_action->sa_mask, SIGUSR2);
}

void	listener(int signal_number)
{
	static int	index;
	size_t	new_position;
	const unsigned char mask = 0b10000000;

	if (signal_number == SIGUSR1)
		g_signals.content[g_signals.last] |= (mask >> index);
	else
		g_signals.content[g_signals.last] &= ~(mask >> index);
	index++;
	if (index < 8)
		return ;
	index = 0;
	new_position = (g_signals.last + 1) % QUEUE_SIZE;
	if (new_position == g_signals.first)
		return ;
	g_signals.last = new_position;
	g_signals.content[g_signals.last] = 0;
}

void	initialize_deletion_table(unsigned char *table)
{
	int	index;

	index = 0;
	while (index < 0b100000)
		table[index++] = 2; // impossible to identify
	table[0b01101] = 0; // Swap or deletion
	table[0b10110] = 0; // Swap
	table[0b01001] = 0; // Swap or deletion
	table[0b10010] = 0; // Swap
	table[0b01110] = 0; // OK
	table[0b10001] = 0; // OK
	table[0b01100] = 1;
	table[0b01111] = 1;
	table[0b11100] = 1;
	table[0b11101] = 1;
	table[0b00010] = 1;
	table[0b00011] = 1;
	table[0b10000] = 1;
	table[0b10011] = 1;
}

void	initialize_lookup_table(unsigned char *table)
{
	int	index;

	index = 0;
	while (index < 0b100000)
		table[index++] = 2; // impossible to identify
	table[0b01110] = 0; // Swap or deletion
	table[0b01100] = 0; // Swap
	table[0b01101] = 0; // Swap or deletion
	table[0b01111] = 0; // Swap
	table[0b10110] = 0; // OK
	table[0b11100] = 0; // OK
	table[0b11101] = 0;
	table[0b10001] = 1;
	table[0b00010] = 1;
	table[0b00011] = 1;
	table[0b01001] = 1;
	table[0b10000] = 1;
	table[0b10010] = 1;
	table[0b10011] = 1;
}

void	decode(unsigned char *message, size_t limit)
{
	size_t					decode_index;
	size_t					message_index;
	static unsigned char	is_deletion[0b100000];
	static unsigned char	lookup[0b100000];
	unsigned char			temporary;
	int						decode_bit;
	int						message_bit;

	if (is_deletion[0b10000] != 1)
		initialize_deletion_table(is_deletion);
	if (lookup[0b10001] != 1)
		initialize_lookup_table(lookup);
	decode_index = 0;
	decode_bit = 0;
	message_index = 0;
	message_bit = 0;
	while (decode_index < limit)
	{
		temporary = (unsigned char) (message[decode_index] << decode_bit) >> 3;
		decode_bit = (decode_bit + 5) % 8;
		if (0 < decode_bit && decode_bit < 5)
		{
			decode_index++;
			temporary += message[decode_index] >> (8 - decode_bit);
		}
		if (is_deletion[temporary] == 2)
			continue;
		if (is_deletion[temporary] == 1)
		{
			if (decode_bit == 0)
			{
				decode_bit = 7;
				decode_index--;
			}
			else
				decode_bit--;
		}
		if (lookup[temporary] == 1)
			message[message_index] |= 0b10000000 >> message_bit;
		else
			message[message_index] &= ~(0b10000000 >> message_bit);
		message_bit = (message_bit + 1) % 8;
		if (message_bit == 0)
		{
			ft_write(1, message + message_index, 1);
			message_index++;
		}
	}
	ft_write(1, "\n", 1);
}

void	print_message(void *message)
{
	char	*string;
	size_t	limit;

	limit = g_signals.last;
	g_signals.content = malloc(QUEUE_SIZE + 1);
	g_signals.last = 0;
	decode(message, limit);
	string = message;
	ft_write(STDOUT_FILENO, "\n", 1);
	ft_write(STDOUT_FILENO, string, ft_strlen(string));
	ft_write(STDOUT_FILENO, "\n", 1);
	free(message);
}


void	terminator(int signal_number)
{
	(void) signal_number;
	
	print_message(g_signals.content);
	free(g_signals.content);
	exit(1);
}

void	action_constructor(void (*action_handler)(int), const int *signals, int action_flags)
{
	struct sigaction	action;
	int	index;

	action.sa_handler = action_handler;
	action.sa_flags = action_flags;
	sigemptyset(&action.sa_mask);
	index = 0;
	while (signals[index] != 0)
	{
		sigaddset(&action.sa_mask, signals[index]);
		sigaction(signals[index], &action, NULL);
		index++;
	}
}

void	setup_interrupter(void)
{
	const int	signals[] = {SIGINT, SIGQUIT, SIGTSTP, 0};
	action_constructor(&terminator, signals, 0);
}

void	receiver_constructor(void)
{
	const int	signals[] = {SIGUSR1, SIGUSR2, 0};
	action_constructor(&listener, signals, 0);
}

int	main(void)
{
	int	tries;

	receiver_constructor();
	setup_interrupter();
	g_signals.content = malloc(QUEUE_SIZE + 1);
	if (print_pid() || g_signals.content == NULL)
		return (1);
	g_signals.first = 0;
	g_signals.last = 0;
	g_signals.content[g_signals.last] = 0;
	while (1)
	{
		tries = 0;
		while (tries < 5)
		{
			if (g_signals.last != 0 && usleep(1000) == 0)
			{
				tries = 0;
				print_message(g_signals.content);
			}
			tries++;
		}
		pause();
	}
}
