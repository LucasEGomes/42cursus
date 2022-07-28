/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:36:17 by luceduar          #+#    #+#             */
/*   Updated: 2022/07/27 22:41:15 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

int	is_conversion(char *string)
{
	if (*string != '%' || ft_strchr(CONVERSIONS, *(string + 1)) == NULL)
		return (0);
	return (1);
}

char	*next_conversion(char *string)
{
	size_t	index;

	if (string == NULL)
		return (NULL);
	index = 0;
	while (string + index && !is_conversion(string + index))
		index++;
	return (string + index);
}
