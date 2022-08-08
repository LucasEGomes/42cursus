/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:03:27 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 23:10:06 by luceduar         ###   ########.fr       */
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
	unsigned int		base_length;
	unsigned int		remainder;
	int					digits;

	base_length = ft_strlen(base);
	if (base_length < 2 && !is_valid_base(base))
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
	string[digits--] = '\0';
	while (digits >= 0)
	{
		string[digits--] = base[number % base_length];
		number /= base_length;
	}
	return (string);
}

char	*ft_sizetoa_base(size_t number, char *base)
{
	char		*string;
	size_t		base_length;
	size_t		remainder;
	int			digits;

	base_length = ft_strlen(base);
	if (base_length < 2 && !is_valid_base(base))
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
	string[digits--] = '\0';
	while (digits >= 0)
	{
		string[digits--] = base[number % base_length];
		number /= base_length;
	}
	return (string);
}
