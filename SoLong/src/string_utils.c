/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:01:04 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 22:17:06 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	(void) string;
	(void) end;
	return (0);
}
