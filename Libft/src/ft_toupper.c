/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:31 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:28:31 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_lowercase(int c)
{
	if ((c < 'a') || (c > 'z'))
		return (0);
	return (1);
}

int	ft_toupper(int c)
{
	if (!is_lowercase(c))
		return (c);
	return (c - 'a' + 'A');
}
