/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/13 18:19:32 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*line;
	char	*temp;
	size_t	index;
	size_t	line_size;
	size_t	temp_index;
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 1)
		return (NULL);
	index = 0;
	line_size = (BUFFER_SIZE + 1);
	line = malloc(sizeof(*line) * line_size);
	if (line == NULL)
		return (NULL);
	line[BUFFER_SIZE - 1] = '\0';
	while (read_bytes > 0 && buffer[index] != '\n')
	{
		line[line_size + index - BUFFER_SIZE - 1] = buffer[index];
		index++;
		if (index == BUFFER_SIZE)
		{
			temp = line;
			line_size += BUFFER_SIZE;
			line = malloc(sizeof(*line) * line_size);
			if (line == NULL)
			{
				free(temp);
				return (NULL);
			}
			line[BUFFER_SIZE - 1] = '\0';
			temp_index = 0;
			while (temp != NULL && temp[temp_index] != '\0')
			{
				line[temp_index] = temp[temp_index];
				temp_index++;
			}
			free(temp);
			read_bytes = read(fd, buffer, BUFFER_SIZE);
			index = 0;
		}
	}
	temp_index = 0;
	while (temp_index <= index)
	{
		line[line_size + temp_index - BUFFER_SIZE - 1] = buffer[temp_index];
		temp_index++;
	}
	line[line_size + temp_index - BUFFER_SIZE - 1] = '\0';
	return (line);
}
