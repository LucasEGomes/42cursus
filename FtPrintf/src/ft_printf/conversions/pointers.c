/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:54:41 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 22:58:41 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

int	print_pointer(va_list ap)
{
	size_t	pointer;
	char	*text;
	int		length;

	pointer = va_arg(ap, size_t);
	if (pointer == 0)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	ft_putstr_fd("0x", STDOUT_FILENO);
	text = ft_sizetoa_base(pointer, "0123456789abcdef");
	if (text == NULL)
		return (0);
	length = ft_strlen(text);
	ft_putstr_fd(text, STDOUT_FILENO);
	free(text);
	return (length + 2);
}
