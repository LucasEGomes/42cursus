/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:22 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 13:59:11 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	number[12];
	int		digits;
	int		is_negative;

	if (n == 0)
		return (ft_putchar_fd('0', fd));
	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	digits = 11;
	number[digits] = '\0';
	while (n != 0)
	{
		digits--;
		number[digits] = "0123456789"[(n % 10) * (1 - 2 * is_negative)];
		n = n / 10;
	}
	if (is_negative)
		number[digits - 1] = '-';
	ft_putstr_fd(&number[digits - is_negative], fd);
}
