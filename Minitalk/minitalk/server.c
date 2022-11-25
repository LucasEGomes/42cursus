#include "server.h"
#include "ft_write.h"
#include "ft_itoa.h"
#include "ft_strlen.h"
#include <stdlib.h>

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
	ft_write(STDOUT_FILENO, "FAILED TO INITIALIZE SERVER\n", 29);
	return (1);
}

int	main(void)
{
	g_signal_queue.content = malloc(QUEUE_SIZE);
	if (print_pid() || g_signal_queue.content == NULL)
		return (1);
	g_signal_queue.first = 0;
	g_signal_queue.last = 0;
	return (0);
}
