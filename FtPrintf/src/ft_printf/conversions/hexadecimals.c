/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:53:49 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 22:58:50 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

int	print_hexadecimal(unsigned int number, int is_upper)
{
	char	*text;
	int		length;

	if (is_upper)
		text = ft_uitoa_base(number, "0123456789ABCDEF");
	else
		text = ft_uitoa_base(number, "0123456789abcdef");
	if (text == NULL)
		return (0);
	length = ft_strlen(text);
	ft_putstr_fd(text, STDOUT_FILENO);
	free(text);
	return (length);
}

int	print_lower_hexadecimal(va_list ap)
{
	return (print_hexadecimal(va_arg(ap, unsigned int), 0));
}

int	print_upper_hexadecimal(va_list ap)
{
	return (print_hexadecimal(va_arg(ap, unsigned int), 1));
}
