/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/27 20:10:13 by luceduar         ###   ########.fr       */
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

static char	*pop_buffer(char *destiny, t_buffer *buffer, ssize_t size)
{
	char	*auxiliar;
	ssize_t	index;

	auxiliar = destiny;
	while (*auxiliar != '\0')
		auxiliar++;
	index = 0;
	while (index < buffer->size)
	{
		if (index < size)
			auxiliar[index] = buffer->string[index];
		else
			buffer->string[index - size] = buffer->string[index];
		index++;
	}
	auxiliar[size] = '\0';
	buffer->size -= size;
	return (destiny);
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

static char	*append_buffer(char *destiny, t_buffer *buffer, ssize_t size)
{
	destiny = increase_string(destiny, size);
	if (destiny == NULL)
		return (NULL);
	return (pop_buffer(destiny, buffer, size));
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
	while (buffer.size > 0 && buffer.string[index] != '\n')
	{
		if (++index == buffer.size)
		{
			line = append_buffer(line, &buffer, index);
			if (line == NULL)
				return (NULL);
			index = 0;
			buffer.size = read(fd, buffer.string, BUFFER_SIZE);
		}
	}
	if (buffer.string[index] == '\n')
		index++;
	return (append_buffer(line, &buffer, index));
}
