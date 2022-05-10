/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:33 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:28:33 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_uppercase(int c)
{
	if ((c < 'A') || (c > 'Z'))
		return (0);
	return (1);
}

int	ft_tolower(int c)
{
	if (!is_uppercase(c))
		return (c);
	return (c + 'a' - 'A');
}
