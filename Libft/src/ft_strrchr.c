/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:46 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 23:11:13 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*result;
	char	byte;

	result = NULL;
	byte = (char) c;
	while (s[index] != '\0')
	{
		if (s[index] == byte)
			result = (char *) &s[index];
		index++;
	}
	if (byte == '\0')
		return ((char *) &s[index]);
	return (result);
}
