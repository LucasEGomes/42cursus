/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/18 21:01:55 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*increase_string(char *string, size_t size)
{
	char	*old_string;
	size_t	original_size;
	size_t	index;

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

static char	*append_buffer(char *string, char *buffer, size_t start, size_t end)
{
	size_t	index;
	size_t	size;

	size = end - start;
	string = increase_string(string, size);
	if (string == NULL)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
		index++;
	string[index + size] = '\0';
	while (end > start)
	{
		end--;
		string[index + end - start] = buffer[end];
		buffer[end] = '\0';
	}
	return (string);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	ssize_t		index;
	ssize_t		start;
	ssize_t		read_bytes;

	index = 0;
	while (index < BUFFER_SIZE && buffer[index] == '\0')
		index++;
	if (index == BUFFER_SIZE)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 1)
			return (NULL);
		start = 0;
		index = 0;
	}
	else
	{
		start = index;
		read_bytes = BUFFER_SIZE;
	}
	line = NULL;
	while (read_bytes > 0)
	{
		if (buffer[index] == '\n')
			return (append_buffer(line, buffer, start, index + 1));
		if (buffer[index] == '\0')
			return (append_buffer(line, buffer, start, index));
		index++;
		if (index == read_bytes)
		{
			line = append_buffer(line, buffer, start, read_bytes);
			if (line == NULL)
				return (NULL);
			index = 0;
			start = 0;
			read_bytes = read(fd, buffer, read_bytes);
		}
	}
	return (line);
}
