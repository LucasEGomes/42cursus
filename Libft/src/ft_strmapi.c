/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:55 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 11:05:43 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped_string;
	size_t	index;

	mapped_string = malloc(sizeof(*mapped_string) * (ft_strlen(s) + 1));
	if (mapped_string == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		mapped_string[index] = f(index, s[index]);
		index++;
	}
	mapped_string[index] = '\0';
	return (mapped_string);
}
