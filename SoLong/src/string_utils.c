/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:01:04 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/15 18:31:12 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"
#include <stdlib.h>

size_t	string_length(char *string)
{
	size_t	length;

	length = 0;
	while (*string++ != '\0')
		length++;
	return (length);
}

char	*string_join(char *left, char *right)
{
	char	*result;
	char	*temp;
	size_t	size;

	if (left == NULL || right == NULL)
		return (NULL);
	size = string_length(left) + string_length(right) + 1;
	result = malloc(size * sizeof(*result));
	if (result == NULL)
		return (NULL);
	temp = result;
	while (*left != '\0')
		*temp++ = *left++;
	while (*right != '\0')
		*temp++ = *right++;
	*temp = '\0';
	return (result);
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
