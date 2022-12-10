#include "minitalk_bonus.h"
#include "server_bonus.h"
#include "utils/ft_write.h"
#include "utils/ft_itoa.h"
#include "utils/ft_strlen.h"
#include "utils/ft_print.h"
#include "minitalk_errors.h"
#include <stdlib.h>
#include <signal.h>

t_server_metadata	g_metadata;

void	receiver_constructor(void);

void	print_pid(void)
{
	ft_print_str(STDOUT_FILENO, "Server Process ID (PID): ");
	ft_print_int(STDOUT_FILENO, getpid());
	ft_write(STDOUT_FILENO, "\n", 1);
}

unsigned char	set_bit(unsigned char value, int bit_value, int index)
{
	const unsigned char	mask = 0b10000000;

	if (bit_value)
		return (value | (mask >> index));
	return (value & ~(mask >> index));
}

void	reset_server(void)
{
	g_metadata.bit_index = 0;
	g_metadata.content_index = 0;
}

void	receiver(int signal, siginfo_t *info, void *context)
{
	int	bit;
	unsigned char	byte;

	(void) context;
	bit = (signal == BIT_1);
	byte = g_metadata.content[g_metadata.content_index];
	g_metadata.content[g_metadata.content_index] = set_bit(byte , bit, g_metadata.bit_index);
	g_metadata.bit_index++;
	if (g_metadata.bit_index >= 8)
	{
		g_metadata.content_index++;
		if (g_metadata.content[g_metadata.content_index - 1] == '\0'
			|| g_metadata.content_index == QUEUE_SIZE)
		{
			ft_write(STDOUT_FILENO, g_metadata.content, g_metadata.content_index);
			reset_server();
		}
		g_metadata.bit_index = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		reset_server();

}

void	action_constructor(void (*action_handler)(int, siginfo_t *, void *), const int *signals, int action_flags)
{
	struct sigaction	action;
	int	index;

	action.sa_sigaction = action_handler;
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

void	receiver_constructor(void)
{
	const int	signals[] = {SIGUSR1, SIGUSR2, 0};
	action_constructor(&receiver, signals, SA_SIGINFO);
}

void	terminator(int signal, siginfo_t *info, void *context)
{
	(void) signal;
	(void) info;
	(void) context;
	
	ft_print_str(STDOUT_FILENO, "\nClosing server...\n");
	free(g_metadata.content);
	exit(0);
}

void	terminator_constructor(void)
{
	const int	signals[] = {SIGINT, SIGQUIT, SIGTSTP, 0};
	action_constructor(&terminator, signals, SA_SIGINFO);
}

void	queue_constructor(t_server_metadata	*queue, size_t queue_size)
{
	queue->content = malloc(queue_size + 1);
	if (queue->content == NULL)
		return ;
	queue->content[queue_size] = '\0';
	queue->content_index = 0;
	queue->bit_index = 0;
}

int	main(void)
{
	ft_print_str(STDOUT_FILENO, "Starting server...\n");
	queue_constructor(&g_metadata, QUEUE_SIZE);
	if (g_metadata.content == NULL)
		return (failed_to_initialize_server());
	receiver_constructor();
	terminator_constructor();
	print_pid();
	while (1)
		pause();
}
