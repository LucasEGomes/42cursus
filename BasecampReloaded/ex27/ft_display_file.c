/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:03:04 by mascote           #+#    #+#             */
/*   Updated: 2022/04/06 00:04:26 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

#define BUFFER_SIZE 80

void	ft_putstr(char *string)
{
	int	length;

	length = 0;
	while (string[length] != '\0')
		length++;
	write(1, string, length);
}

void	read_file(int file_descriptor)
{
	char	buffer[BUFFER_SIZE];
	int		read_bytes;

	read_bytes = BUFFER_SIZE;
	while (read_bytes >= BUFFER_SIZE)
	{
		read_bytes = read(file_descriptor, buffer, BUFFER_SIZE);
		write(1, buffer, read_bytes);
	}
}
