/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:50 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:33:26 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		index;
	const char	temp;

	while (big[index] != '\0' & index < len)
	{
		index = 0;
		while (big[index] == little[index])
			index++;
		if (little[index == '\0'])
			return (big);
		big++;
	}
	return (NULL);
}
