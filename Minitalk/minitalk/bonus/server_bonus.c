#include "server.h"
#include "utils/ft_write.h"
#include "utils/ft_itoa.h"
#include "utils/ft_strlen.h"
#include "utils/ft_print.h"
#include "minitalk_errors.h"
#include <stdlib.h>
#include <signal.h>

t_deque	g_signals;

void	print_pid(void)
{
	ft_print_int(STDOUT_FILENO, getpid());
}

unsigned char	set_bit(unsigned char value, int bit_value, int index)
{
	const unsigned char	mask = 0b10000000;

	if (bit_value)
		return (value | (mask >> index));
	return (value & ~(mask >> index));
}

void	receiver(int signal_number, siginfo_t *sender, void *_)
{
	int			current_bit;
	const int	bits = sizeof(*g_signals.content) * 8;

	current_bit = (signal_number == SIGUSR1);
	set_bit(current_bit, g_signals.bit_index, g_signals.last);
	g_signals.bit_index = (g_signals.bit_index + 1) % bits;
	if (g_signals.bit_index == 0)
		g_signals.last++;
	kill(sender->si_pid, signal_number);
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

void	terminator_constructor(void)
{
	const int	signals[] = {SIGINT, SIGQUIT, SIGTSTP, 0};
	action_constructor(&terminator, signals, 0);
}

void	receiver_constructor(void)
{
	const int	signals[] = {SIGUSR1, SIGUSR2, 0};
	action_constructor(&receiver, signals, 0);
}

void	queue_constructor(t_deque	*queue, size_t queue_size)
{
	queue->content = malloc(queue_size + 1);
	if (queue->content == NULL)
		return ;
	queue->content[queue_size] = '\0';
	queue->last = 0;
}

int	main(void)
{
	queue_constructor(&g_signals, QUEUE_SIZE);
	if (g_signals.content == NULL)
		return (failed_to_initialize_server());
	receiver_constructor();
	terminator_constructor();
	print_pid();
	while (1)
		pause();
}
