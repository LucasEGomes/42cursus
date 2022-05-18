/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/18 00:33:13 by luceduar         ###   ########.fr       */
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

static char	*append_buffer(char *string, char *buffer, size_t size)
{
	size_t	index;

	string = increase_string(string, size);
	if (string == NULL)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
		index++;
	string[index + size] = '\0';
	while (size > 0)
	{
		size--;
		string[index + size] = buffer[size];
	}
	return (string);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*line;
	ssize_t	index;
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 1)
		return (NULL);
	line = NULL;
	index = 0;
	while (read_bytes > 0)
	{
		if (buffer[index] == '\n')
			return (append_buffer(line, buffer, index + 1));
		index++;
		if (index == read_bytes)
		{
			line = append_buffer(line, buffer, read_bytes);
			if (line == NULL)
				return (NULL);
			index = 0;
			read_bytes = read(fd, buffer, read_bytes);
		}
	}
	return (line);
}
