/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:03 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 23:08:18 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dst_size;

	index = 0;
	while ((dst[index] != '\0') & (index < size))
		index++;
	if (index == size)
		return (index);
	dst_size = index;
	index = 0;
	while (index < size - dst_size - 1)
	{
		dst[dst_size + index] = src[index];
		if (src[index] == '\0')
			return (index + dst_size);
		index++;
	}
	return (size);
}
