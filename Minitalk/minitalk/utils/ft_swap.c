/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:06:54 by luceduar          #+#    #+#             */
/*   Updated: 2022/12/10 08:06:54 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(void *value_1, void *value_2, size_t size)
{
	char	*string_1;
	char	*string_2;
	char	temporary;
	size_t	index;

	index = 0;
	string_1 = value_1;
	string_2 = value_2;
	while (index < size)
	{
		temporary = string_2[index];
		string_2[index] = string_1[index];
		string_1[index] = temporary;
		index++;
	}
}
