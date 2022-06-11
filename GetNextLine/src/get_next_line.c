/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/11 14:28:44 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	char			*line;
	ssize_t			index;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	construct_buffer(&buffer, fd);
	if (buffer.string == NULL)
		return (NULL);
	index = 0;
	line = NULL;
	while (buffer.size > 0 && buffer.string[index++] != '\n')
	{
		if (index == buffer.size)
		{
			line = append_buffer(line, &buffer, index);
			if (line == NULL)
				return (NULL);
			index = 0;
			buffer.size = read(fd, buffer.string, BUFFER_SIZE);
		}
	}
	return (append_buffer(line, &buffer, index));
}
