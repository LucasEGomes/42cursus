/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:03:27 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 01:15:08 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static int	is_valid_base(char *base)
{
	size_t	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (ft_strchr(base, base[index]) != base + index)
			return (0);
		index++;
	}
	return (1);
}

char	*ft_uitoa_base(unsigned int number, char *base)
{
	char				*string;
	unsigned int					base_length;
	unsigned int		remainder;
	int					digits;
	int					digit;

	base_length = ft_strlen(base);
	if (base_length < 2)
		return (NULL);
	if (!is_valid_base(base))
		return (NULL);
	digits = 1;
	remainder = number;
	while (remainder >= base_length)
	{
		remainder /= base_length;
		digits++;
	}
	string = malloc(sizeof(*string) * (digits + 1));
	if (string == NULL)
		return (NULL);
	string[digits] = '\0';
	digit = digits - 1;
	while(digit >= 0)
	{
		string[digit--] = base[number % base_length];
		number /= base_length;
	}
	return (string);
}
