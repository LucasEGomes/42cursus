/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:03:10 by mascote           #+#    #+#             */
/*   Updated: 2022/04/06 00:04:30 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*result;
	unsigned int	size;
	unsigned int	index;

	if (min >= max)
		return (NULL);
	size = min + 1;
	size = max - size + 1;
	result = malloc(sizeof(*result) * ((size_t)size));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		result[index] = min + index;
		index++;
	}
	return (result);
}
