#include "minitalk_bonus.h"
#include "client_bonus.h"
#include "minitalk_errors.h"
#include "utils/ft_strlen.h"
#include "utils/ft_write.h"
#include "utils/ft_atoi.h"
#include <signal.h>

t_metadata	g_metadata;

int	get_bit(unsigned char value, int index)
{
	const unsigned char	mask = 0b10000000;

	return ((value & (mask >> index)) > 0);
}

void	send_bit(pid_t process_id, unsigned char value, int index)
{
	int	signal;

	signal = BIT_0;
	if (get_bit(value, index))
		signal = BIT_1;
	g_metadata.status = CLIENT_WAIT;
	if (kill(process_id, signal) == -1)
		failed_to_send_signal_to_server(process_id);
}

int	wait_acknowledge(int timeout)
{
	int timed_out;
	
	timed_out = 0;
	while (g_metadata.status == CLIENT_WAIT && timed_out < timeout)
		timed_out++;
	if (g_metadata.status == CLIENT_WAIT)
		return (0);
	return (1);
}

void	send_byte(pid_t process_id, unsigned char value, int retry_limit, useconds_t timeout)
{
	int	index;
	int	tries;
	
	index = 0;
	tries = 0;
	while (index < 8)
	{
		if (tries >= retry_limit)
			failed_to_acquire_acknowledge_from_server(process_id);
		send_bit(process_id, value, index);
		if (wait_acknowledge(timeout) == 0)
			tries++;
		else
		{
			index++;
			tries = 0;
		}
	}
}

static void	acknowledger(int signal_number, siginfo_t *info, void *context)
{
	(void) signal_number;
	(void) context;
	if (info->si_pid == g_metadata.server_pid)
		g_metadata.status = CLIENT_RESUME;
}

static void	health_check(int signal_number, siginfo_t *info, void *context)
{
	(void) signal_number;
	(void) info;
	(void) context;
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

void	acknowledge_constructor(void)
{
	const int	signals[] = {SIGUSR1, 0};
	action_constructor(&acknowledger, signals, SA_SIGINFO);
}

void	health_check_constructor(void)
{
	const int	signals[] = {SIGUSR2, 0};
	action_constructor(&health_check, signals, SA_SIGINFO);
}

int	main(int argc, char **argv)
{
	unsigned char	*message;

	if (argc != 3)
		return (invalid_number_of_arguments());
	acknowledge_constructor();
	g_metadata.server_pid = ft_atoi(argv[1]);
	message = (void *) argv[2];
	g_metadata.status = CLIENT_RESUME;
	while (*message != '\0')
		send_byte(g_metadata.server_pid, *message++, RETRY_LIMIT, TIMEOUT_USECONDS);
	send_byte(g_metadata.server_pid, '\0', RETRY_LIMIT, TIMEOUT_USECONDS);
	return (0);
}
