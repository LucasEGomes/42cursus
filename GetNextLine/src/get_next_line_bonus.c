/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/01 19:36:31 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_buffer		buffers[512];
	t_buffer		*buffer;
	char			*line;
	ssize_t			index;

	buffer = &buffers[fd];
	construct_buffer(buffer, fd);
	if (buffer->string == NULL || buffer->size == 0)
		return (NULL);
	index = 0;
	line = NULL;
	while (buffer->size > 0 && buffer->string[index] != '\n')
	{
		if (++index == buffer->size)
		{
			line = append_buffer(line, buffer, index);
			if (line == NULL)
				return (NULL);
			index = 0;
			buffer->size = read(fd, buffer->string, BUFFER_SIZE);
		}
	}
	if (buffer->string[index] == '\n')
		index++;
	return (append_buffer(line, buffer, index));
}
