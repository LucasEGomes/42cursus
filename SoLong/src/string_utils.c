/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:01:04 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 22:43:59 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

size_t	string_length(char *string)
{
	size_t	length;

	length = 0;
	while (*string++ != '\0')
		length++;
	return (length);
}

int	string_ends_with(char *string, char *end)
{
	size_t	index;

	while (*string != '\0')
	{
		index = 0;
		while (string[index] == end[index] && \
			string[index] != '\0' && end[index] != '\0')
			index++;
		if (string[index] == end[index] && end[index] == '\0')
			return (1);
		string++;
	}
	return (0);
}
