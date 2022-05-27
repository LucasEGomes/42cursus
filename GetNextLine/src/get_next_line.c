/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/27 00:10:36 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*increase_string(char *string, ssize_t size)
{
	char	*old_string;
	ssize_t	original_size;
	ssize_t	index;

	if (size == 0)
		return (string);
	original_size = 0;
	while (string != NULL && string[original_size] != '\0')
		original_size++;
	old_string = string;
	string = malloc((original_size + size + 1) * sizeof(*string));
	if (string == NULL)
	{
		free(old_string);
		return (NULL);
	}
	index = 0;
	while (index < original_size)
	{
		string[index] = old_string[index];
		index++;
	}
	free(old_string);
	string[index] = '\0';
	return (string);
}

static char	*pop_buffer(char *string, t_buffer *buffer, ssize_t size)
{
	ssize_t	index;
	ssize_t	buffer_index;

	string = increase_string(string, size);
	if (string == NULL)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
		index++;
	string[index + size] = '\0';
	buffer_index = 0;
	while (buffer_index < buffer->size)
	{
		if (buffer_index < size)
			string[index + buffer_index] = buffer->string[buffer_index];
		else
			buffer->string[buffer_index - size] = buffer->string[buffer_index];
		buffer_index++;
	}
	buffer->size -= size;
	return (string);
}

void	construct_buffer(t_buffer *buffer, int file_descriptor)
{
	if (buffer->string == NULL)
	{
		buffer->string = malloc(sizeof(*(buffer->string)) * BUFFER_SIZE);
		buffer->size = 0;
		if (buffer->string == NULL)
			return ;
	}
	if (buffer->size == 0)
	{
		buffer->size = read(file_descriptor, buffer->string, BUFFER_SIZE);
		if (buffer->size == 0)
		{
			free(buffer->string);
			buffer->string = NULL;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	char			*line;
	ssize_t			index;

	construct_buffer(&buffer, fd);
	if (buffer.string == NULL)
		return (NULL);
	index = 0;
	line = NULL;
	while (buffer.size > 0 && \
		buffer.string[index] != '\n' && buffer.string[index] != '\0')
	{
		if (++index == buffer.size)
		{
			line = pop_buffer(line, &buffer, index);
			if (line == NULL)
				return (NULL);
			index = 0;
			buffer.size = read(fd, buffer.string, BUFFER_SIZE);
		}
	}
	if (buffer.string[index] == '\n')
		return (pop_buffer(line, &buffer, index + 1));
	return (pop_buffer(line, &buffer, index));
}
