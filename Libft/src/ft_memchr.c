/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:44 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:29:44 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*us;
	unsigned char	uc;

	us = s;
	uc = c;
	index = 0;
	while (us[index] != uc & index < n - 1)
		index++;
	if (us[index] != uc)
		return (NULL);
	return (&s[index]);
}
