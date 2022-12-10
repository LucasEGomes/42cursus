/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:09:16 by luceduar          #+#    #+#             */
/*   Updated: 2022/12/10 08:17:59 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "server_bonus.h"
#include "action_setter.h"
#include "utils/ft_write.h"
#include "utils/ft_itoa.h"
#include "utils/ft_strlen.h"
#include "utils/ft_print.h"
#include "minitalk_errors.h"
#include <stdlib.h>
#include <signal.h>

t_server_metadata	g_data;

unsigned char	set_bit(unsigned char value, int bit_value, int index)
{
	const unsigned char	mask = 0b10000000;

	if (bit_value)
		return (value | (mask >> index));
	return (value & ~(mask >> index));
}

void	reset_server(void)
{
	g_data.bit_index = 0;
	g_data.content_index = 0;
}

void	listener(int signal, siginfo_t *info, void *context)
{
	int	bit;

	(void) context;
	bit = (signal == BIT_1);
	g_data.content[g_data.content_index] = set_bit(
			g_data.content[g_data.content_index], bit, g_data.bit_index);
	g_data.bit_index++;
	if (g_data.bit_index >= 8)
	{
		g_data.content_index++;
		if (g_data.content[g_data.content_index - 1] == '\0'
			|| g_data.content_index == QUEUE_SIZE)
		{
			ft_write(STDOUT_FILENO, g_data.content, g_data.content_index);
			reset_server();
		}
		g_data.bit_index = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		reset_server();
}

void	terminator(int signal, siginfo_t *info, void *context)
{
	(void) signal;
	(void) info;
	(void) context;
	ft_print_str(STDOUT_FILENO, "\nClosing server...\n");
	free(g_data.content);
	exit(0);
}

int	main(void)
{
	const int	listener_signals[] = {SIGUSR1, SIGUSR2, 0};
	const int	terminator_signals[] = {SIGINT, SIGQUIT, SIGTSTP, 0};

	ft_print_str(STDOUT_FILENO, "Starting server...\n");
	g_data.content = malloc(QUEUE_SIZE + 1);
	if (g_data.content == NULL)
		return (failed_to_initialize_server());
	g_data.content[QUEUE_SIZE] = '\0';
	g_data.content_index = 0;
	g_data.bit_index = 0;
	action_setter(&listener, listener_signals, SA_SIGINFO);
	action_setter(&terminator, terminator_signals, SA_SIGINFO);
	ft_print_str(STDOUT_FILENO, "Server Process ID (PID): ");
	ft_print_int(STDOUT_FILENO, getpid());
	ft_write(STDOUT_FILENO, "\n", 1);
	while (1)
		pause();
}
