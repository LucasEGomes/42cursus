/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:06:37 by luceduar          #+#    #+#             */
/*   Updated: 2022/12/10 08:11:12 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "client.h"
#include "action_setter.h"
#include "minitalk_errors.h"
#include "utils/ft_strlen.h"
#include "utils/ft_write.h"
#include "utils/ft_atoi.h"
#include <signal.h>

t_metadata	g_metadata;

void	send_bit(pid_t process_id, unsigned char value, int index)
{
	int					signal;
	const unsigned char	mask = 0b10000000;

	signal = BIT_0;
	if ((value & (mask >> index)) > 0)
		signal = BIT_1;
	g_metadata.status = CLIENT_WAIT;
	if (kill(process_id, signal) == -1)
		failed_to_send_signal_to_server(process_id);
}

int	wait_acknowledge(int timeout)
{
	int	timed_out;

	timed_out = 0;
	while (g_metadata.status == CLIENT_WAIT && timed_out < timeout)
	{
		usleep(1);
		timed_out++;
	}
	if (g_metadata.status == CLIENT_WAIT)
		return (0);
	return (1);
}

void	send_byte(pid_t process_id, unsigned char value, int retry_limit,
	int timeout)
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

int	main(int argc, char **argv)
{
	unsigned char	*message;
	const int		acknowleger_signals[] = {SIGUSR1, 0};

	if (argc != 3)
		return (invalid_number_of_arguments());
	action_setter(&acknowledger, acknowleger_signals, SA_SIGINFO);
	g_metadata.server_pid = ft_atoi(argv[1]);
	message = (void *) argv[2];
	g_metadata.status = CLIENT_RESUME;
	while (*message != '\0')
	{
		send_byte(g_metadata.server_pid, *message, RETRY_LIMIT, TIMEOUT);
		message++;
	}
	send_byte(g_metadata.server_pid, '\0', RETRY_LIMIT, TIMEOUT);
	return (0);
}
