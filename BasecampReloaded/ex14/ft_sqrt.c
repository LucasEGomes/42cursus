/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:03:59 by luceduar          #+#    #+#             */
/*   Updated: 2022/04/06 00:04:33 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	divisor;

	divisor = 1;
	while (divisor <= nb / divisor)
	{
		if (divisor * divisor == nb)
			return (divisor);
		divisor++;
	}
	return (0);
}
