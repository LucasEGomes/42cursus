#include "server.h"
#include "ft_write.h"
#include "ft_itoa.h"
#include "ft_strlen.h"
#include <stdlib.h>
#include <signal.h>

t_deque	g_signal_queue;

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

void	add_last(int signal_number)
{
	static int	index;
	size_t	new_position;

	if (signal_number == SIGUSR1)
		g_signal_queue.content[g_signal_queue.last] += 1 << (7 - index);
	index++;
	if (index < 8)
		return ;
	index = 0;
	new_position = (g_signal_queue.last + 1) % QUEUE_SIZE;
	if (new_position == g_signal_queue.first)
		return ;
	g_signal_queue.last = new_position;
	g_signal_queue.content[g_signal_queue.last] = 0;
}

void	free_resources(int signal_number)
{
	(void) signal_number;

	ft_write(STDOUT_FILENO, "\n", 1);
	ft_write(STDOUT_FILENO, g_signal_queue.content, ft_strlen(g_signal_queue.content));
	ft_write(STDOUT_FILENO, "\nFreeing resources.\n", 20);
	free(g_signal_queue.content);
	exit(1);
}

void	setup_action(void (*action_handler)(int), const int *signals, int action_flags)
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

void	setup_interrupt_action(void)
{
	const int	signals[] = {SIGINT, SIGQUIT, SIGTSTP, 0};
	setup_action(&free_resources, signals, 0);
}

void	setup_communication_action(void)
{
	const int	signals[] = {SIGUSR1, SIGUSR2, 0};
	setup_action(&add_last, signals, 0);
}

int	main(void)
{
	setup_communication_action();
	setup_interrupt_action();
	g_signal_queue.content = malloc(QUEUE_SIZE);
	if (print_pid() || g_signal_queue.content == NULL)
		return (1);
	g_signal_queue.first = 0;
	g_signal_queue.last = 0;
	g_signal_queue.content[g_signal_queue.last] = 0;
	while (1)
		pause();
}
