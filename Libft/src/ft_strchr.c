/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:12 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:29:13 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	byte;

	index = 0;
	byte = (char) c;
	while (s[index] != '\0' & s[index] != byte)
		index++;
	if (s[index] == c)
		return (&s[index]);
	return (NULL);
}
