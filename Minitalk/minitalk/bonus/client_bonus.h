/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:09:21 by luceduar          #+#    #+#             */
/*   Updated: 2022/12/10 08:57:05 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# define CLIENT_RESUME 0
# define CLIENT_WAIT 1
# define RETRY_LIMIT 3
# define TIMEOUT 1000000
# include <unistd.h>

typedef struct s_client_metadata
{
	pid_t	server_pid;
	int		status;
}	t_client_metadata;

#endif
