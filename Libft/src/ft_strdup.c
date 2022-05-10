/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:10 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 11:01:51 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*duplicate;

	size = ft_strlen(s) + 1;
	duplicate = malloc(sizeof(*duplicate) * size);
	if (duplicate == NULL)
		return (NULL);
	while (size > 0)
	{
		size--;
		duplicate[size] = s[size];
	}
	duplicate[size] = s[size];
	return (duplicate);
}
