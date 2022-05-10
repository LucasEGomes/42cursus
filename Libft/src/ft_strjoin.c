/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:05 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 12:12:08 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	total;
	char	*new_string;

	size_s1 = ft_strlen(s1);
	total = size_s1 + ft_strlen(s2) + 1;
	new_string = malloc(sizeof(*new_string) * total);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s1, size_s1 + 1);
	ft_strlcat(new_string, s2, total);
	return (new_string);
}
