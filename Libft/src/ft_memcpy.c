/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:31 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:29:31 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	const unsigned char	*str_src;

	str_dest = dest;
	str_src = src;
	while(n != 0)
	{
		n--;
		str_dest[n] = str_src[n];
	}
	return (dest);
}
