/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:38 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/29 00:18:31 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_buffer
{
	char	*string;
	ssize_t	size;
}	t_buffer;

char	*get_next_line(int fd);
char	*append_buffer(char *destiny, t_buffer *buffer, ssize_t size);
void	construct_buffer(t_buffer *buffer, int file_descriptor);

#endif
