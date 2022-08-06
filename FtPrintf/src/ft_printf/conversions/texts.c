/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:55:34 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 22:58:56 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

int	print_char(va_list ap)
{
	ft_putchar_fd((unsigned char)va_arg(ap, int), STDOUT_FILENO);
	return (1);
}

int	print_string(va_list ap)
{
	char	*string;

	string = va_arg(ap, char *);
	if (string == NULL)
	{
		ft_putstr_fd("(null)", STDOUT_FILENO);
		return (6);
	}
	ft_putstr_fd(string, STDOUT_FILENO);
	return (ft_strlen(string));
}

int	print_percent_sign(va_list ap)
{
	(void) ap;
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}
