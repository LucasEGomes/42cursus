/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:56:30 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 22:56:48 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

int	print_signed_int(int number)
{
	char	*text;
	int		length;

	text = ft_itoa(number);
	if (text == NULL)
		return (0);
	length = ft_strlen(text);
	ft_putstr_fd(text, STDOUT_FILENO);
	free(text);
	return (length);
}

int	print_decimal(va_list ap)
{
	return (print_signed_int(va_arg(ap, int)));
}

int	print_integer(va_list ap)
{
	return (print_signed_int(va_arg(ap, int)));
}
