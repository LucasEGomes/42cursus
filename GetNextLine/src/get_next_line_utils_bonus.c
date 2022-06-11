/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:31 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/11 14:55:07 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*append_buffer(char *destiny, t_buffer *buffer, ssize_t size)
{
	destiny = increase_string(destiny, size);
	if (destiny == NULL)
		return (NULL);
	return (pop_buffer(destiny, buffer, size));
}

static void	free_buffer(t_buffer *buffer)
{
	free(buffer->string);
	buffer->string = NULL;
	buffer->size = 0;
}

void	construct_buffer(t_buffer *buffer, int file_descriptor)
{
	if (BUFFER_SIZE < 1 || file_descriptor < 0)
		return (free_buffer(buffer));
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
		if (buffer->size <= 0)
			free_buffer(buffer);
	}
}
