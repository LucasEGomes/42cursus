/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:09:14 by luceduar          #+#    #+#             */
/*   Updated: 2022/12/10 08:54:28 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define QUEUE_SIZE 4096
# define TIMEOUT 1000
# include <unistd.h>
# include <signal.h>

typedef struct s_server_metadata
{
	unsigned char	*content;
	size_t			content_index;
	int				bit_index;
}	t_server_metadata;

#endif
