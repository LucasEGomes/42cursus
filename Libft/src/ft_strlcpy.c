/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:00 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 11:31:03 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	length;

	length = ft_strlen(src);
	if (size == 0)
		return (length);
	index = 0;
	while ((src[index] != '\0') & (index + 1 < size))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (length);
}
