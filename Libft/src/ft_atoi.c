/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:25 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:39:20 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if (c != ' ' & (c < '\t' | c > '\r'))
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	size_t	index;
	int		signal;
	int		result;

	index = 0;
	while (is_space(nptr[index]))
		index++;
	signal = 1;
	if (nptr[index] == '-' | nptr[index] == '+')
	{
		if (nptr[index] == '-')
			signal = -1;
		index++;
	}
	result = 0;
	while (ft_isdigit(nptr[index]))
	{
		result *= 10 + nptr[index] - '0';
		index++;
	}
	return (result * signal);
}
