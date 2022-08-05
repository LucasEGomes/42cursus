/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:36:17 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/04 23:33:27 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

int	is_conversion(char *string)
{
	if (*string != '%' || ft_strchr(CONVERSIONS, *(string + 1)) == NULL)
		return (0);
	return (1);
}

char	*next_conversion(char *string)
{
	size_t	index;

	if (string == NULL)
		return (NULL);
	index = 0;
	while (string[index] && !is_conversion(string + index))
		index++;
	if (!string[index])
		return (NULL);
	return (string + index);
}

int	print_signed_int(int number)
{
	int	length;
	char	*text;

	text = ft_itoa(number);
	if (text == NULL)
		return (0);
	length = ft_strlen(text);
	ft_putstr_fd(text, STDOUT_FILENO);
	free(text);
	return (length);
}

int	print_char(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}
