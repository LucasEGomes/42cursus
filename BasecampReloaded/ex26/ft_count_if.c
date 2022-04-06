/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:03:07 by mascote           #+#    #+#             */
/*   Updated: 2022/04/06 00:04:29 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (tab[index] != ((void *) 0))
	{
		if (f(tab[index]) == 1)
			count++;
		index++;
	}
	return (count);
}
