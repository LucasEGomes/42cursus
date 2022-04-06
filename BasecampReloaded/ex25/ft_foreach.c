/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:03:08 by mascote           #+#    #+#             */
/*   Updated: 2022/04/06 00:04:30 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	index;

	if (length < 1)
		return ;
	index = 0;
	while (index < length)
	{
		f(tab[index]);
		index++;
	}
}
