/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:07:18 by luceduar          #+#    #+#             */
/*   Updated: 2022/12/10 08:07:18 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_digits_int(int number, int base_size)
{
	int	digits;
	int	limit;

	if (base_size < 2)
		return (-1);
	digits = 1;
	limit = base_size - 1;
	while ((number < -limit) | (number > limit))
	{
		number /= base_size;
		digits++;
	}
	return (digits);
}
