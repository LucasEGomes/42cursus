/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:50 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 14:25:43 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t	i;
	size_t	little_size;

	little_size = ft_strlen(little);
	if (little_size == 0)
		return ((char *)big);
	big_index = 0;
	while ((big[big_index] != '\0') & (big_index + little_size - 1 < len))
	{
		i = 0;
		while ((big[big_index + i] == little[i]) & (little[i] != '\0'))
			i++;
		if (little[i] == '\0')
			return ((char *)&big[big_index]);
		big_index++;
	}
	return (NULL);
}
