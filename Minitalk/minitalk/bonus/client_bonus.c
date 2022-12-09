#include "minitalk_bonus.h"
#include "client_bonus.h"
#include "minitalk_errors.h"
#include "utils/ft_strlen.h"
#include "utils/ft_write.h"
#include "utils/ft_atoi.h"
#include <signal.h>
#define DELAY 1000

t_metadata	g_metadata;

int	get_bit(unsigned char value, int index)
{
	const unsigned char	mask = 0b10000000;

	return ((value & (mask >> index)) > 0);
}

void	send_bit(int process_id, unsigned char value, int index)
{
	int	signal;

	signal = BIT_0;
	if (get_bit(value, index))
		signal = BIT_1;
	g_metadata.last_signal_sent = signal;
	g_metadata.status = CLIENT_WAIT;
	kill(process_id, signal);
	while (g_metadata.status == CLIENT_WAIT)
		usleep(DELAY);
}

void	send_byte(int process_id, unsigned char value)
{
	int	index;
	
	index = 0;
	while (index < 8)
	{
		send_bit(process_id, value, index);
		index++;
	}
}
static void	acknowledger(int signal_number, siginfo_t *info, void *context)
{
	(void) signal_number;
	(void) info;
	(void) context;
	g_metadata.status = CLIENT_RESUME;
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
	const int	signals[] = {SIGUSR1, SIGUSR2, 0};
	action_constructor(&acknowledger, signals, SA_SIGINFO);
}

int	main(int argc, char **argv)
{
	unsigned char	*message;
	int				process_id;

	if (argc != 3)
		return (invalid_number_of_arguments());
	acknowledge_constructor();
	process_id = ft_atoi(argv[1]);
	message = (void *) argv[2];
	g_metadata.status = CLIENT_RESUME;
	while (*message != '\0')
		send_byte(process_id, *message++);
	send_byte(process_id, '\0');
	return (0);
}
