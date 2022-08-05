/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:36:17 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/04 23:51:20 by luceduar         ###   ########.fr       */
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
	char	*text;

	text = ft_itoa(number);
	if (text == NULL)
		return (0);
	ft_putstr_fd(text, STDOUT_FILENO);
	free(text);
	return (ft_strlen(text));
}

int	print_char(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

int	print_percent_sign(void)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}

int	print_string(char *string)
{
	if (string == NULL)
	{
		ft_putstr_fd("(null)", STDOUT_FILENO);
		return (6);
	}
	ft_putstr_fd(string, STDOUT_FILENO);
	return (ft_strlen(string));
}
