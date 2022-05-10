/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:30:05 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:38:49 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int	n)
{
	int	digits;
	int	temp;

	digits = 1;
	temp = n;
	while (-9 > temp | temp > 9)
	{
		temp /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		digits;
	int		is_negative;

	
	digits = get_digits(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		digits++;
	}
	number = malloc(sizeof(*number) * (digits + 1));
	if (number == NULL)
		return (NULL);
	number[digits] = '\0';
	while (digits > 0 + is_negative)
	{
		digits--;
		number[digits] = "0123456789"[(n % 10) * (-1 * is_negative)];
	}
	if (is_negative)
		number[0] = '-';
	return (number);
}
