/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:41 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:28:41 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;

	sub_string = malloc(sizeof(*sub_string) * (len + 1));
	if (sub_string == NULL)
		return (NULL);
	return (ft_strlcpy(sub_string, s, len + 1));
}
