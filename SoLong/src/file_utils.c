/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:09:10 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 18:53:32 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"
#include "string_utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	*stop_read(int file_descriptor, char *read_string)
{
	free(read_string);
	close(file_descriptor);
	return (NULL);
}

void	*set_new_read_string(char *read_string, char *buffer)
{
	char	*new_string;

	if (read_string != NULL)
		new_string = string_join(read_string, buffer);
	else
		new_string = string_join("", buffer);
	free(read_string);
	return (new_string);
}

char	*read_all_file(char *filename)
{
	char	*result;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	int		file_descriptor;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor < 0)
		return (stop_read(file_descriptor, NULL));
	result = NULL;
	read_bytes = read(file_descriptor, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		result = set_new_read_string(result, buffer);
		if (result == NULL)
			return (NULL);
		read_bytes = read(file_descriptor, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (stop_read(file_descriptor, result));
	}
	close(file_descriptor);
	if (*result == '\0')
		return (NULL);
	return (result);
}
