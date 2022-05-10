/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:41 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 14:32:56 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	size;

	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	size = size - start;
	if (size > len)
		size = len;
	sub_string = malloc(sizeof(*sub_string) * (size + 1));
	if (sub_string == NULL)
		return (NULL);
	ft_strlcpy(sub_string, &s[start], size + 1);
	return (sub_string);
}
