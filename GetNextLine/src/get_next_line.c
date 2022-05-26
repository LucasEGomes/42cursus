/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/24 22:56:08 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*increase_string(char *string, size_t size)
{
	char	*old_string;
	size_t	original_size;
	size_t	index;

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

static char	*pop_buffer(char *string, char *buffer, size_t size)
{
	size_t	index;
	size_t	buffer_index;

	if (size < BUFFER_SIZE && buffer[size] == '\n')
		size++;
	string = increase_string(string, size);
	if (string == NULL)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
		index++;
	string[index + size] = '\0';
	buffer_index = 0;
	while (buffer_index < size)
	{
		string[index + buffer_index] = buffer[buffer_index];
		buffer[buffer_index++] = '\0';
	}
	while (buffer_index < BUFFER_SIZE && buffer[buffer_index] != '\0')
	{
		buffer[buffer_index - size] = buffer[buffer_index];
		buffer[buffer_index++] = '\0';
	}
	return (string);
}

char	*construct_buffer(char *buffer, int file_descriptor)
{
	ssize_t	index;

	if (buffer == NULL)
	{
		buffer = malloc(BUFFER_SIZE);
		if (buffer == NULL)
			return (NULL);
		index = 0;
		while (index < BUFFER_SIZE)
		{
			buffer[index] = '\0';
			index++;
		}
	}
	if (buffer[0] == '\0')
	{
		if (read(file_descriptor, buffer, BUFFER_SIZE) == 0)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		index;
	ssize_t		read_bytes;

	buffer = construct_buffer(buffer, fd);
	if (buffer == NULL)
		return (NULL);
	read_bytes = 0;
	while (read_bytes < BUFFER_SIZE && buffer[read_bytes] != '\0')
		read_bytes++;
	index = 0;
	line = NULL;
	while (read_bytes > 0 && buffer[index] != '\n' && buffer[index] != '\0')
	{
		if (++index == read_bytes)
		{
			line = pop_buffer(line, buffer, read_bytes);
			if (line == NULL)
				return (NULL);
			index = 0;
			read_bytes = read(fd, buffer, read_bytes);
		}
	}
	return (pop_buffer(line, buffer, index));
}
