/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:08:58 by luceduar          #+#    #+#             */
/*   Updated: 2022/12/10 08:51:36 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	action_setter(void (*action_handler)(int, siginfo_t *, void *),
	const int *signals, int action_flags)
{
	struct sigaction	action;
	int					index;

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
