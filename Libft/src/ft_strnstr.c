/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:50 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 01:24:40 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		index;

	while ((big[index] != '\0') & (index < len))
	{
		index = 0;
		while (big[index] == little[index])
			index++;
		if (little[index == '\0'])
			return ((char *) big);
		big++;
	}
	return (NULL);
}
