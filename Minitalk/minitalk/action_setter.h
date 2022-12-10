/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_setter.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:08:56 by luceduar          #+#    #+#             */
/*   Updated: 2022/12/10 08:13:14 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_SETTER_H
# define ACTION_SETTER_H
# include <signal.h>

void	action_setter(void (*action_handler)(int, siginfo_t *, void *), \
	const int *signals, int action_flags);

#endif
