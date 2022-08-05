/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:08:24 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 00:49:50 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf_utils.h"

int	test_ft_uitoa_base(unsigned int number, char *base, char *expected)
{
	char	*value;
	int		result;

	value = ft_uitoa_base(number, base);
	result = ASSERT_STRING(expected, value);
	free(value);
	return (result);
}

int	test_ft_printf_utils(void)
{
	int	result;

	result = 1;
	result &= test_ft_uitoa_base(42U, "0123456789ABCDEF", "2A");
	result &= test_ft_uitoa_base(0U, "0123456789ABCDEF", "0");
	result &= test_ft_uitoa_base(4294967295U, "0123456789ABCDEF", "FFFFFFFF");
	result &= test_ft_uitoa_base(123456U, "0123456789ABCDEF", "1E240");
	result &= test_ft_uitoa_base(42U, "01", "101010");
	result &= test_ft_uitoa_base(42U, "", NULL);
	result &= test_ft_uitoa_base(42U, "z", NULL);
	result &= test_ft_uitoa_base(42U, "AA", NULL);
	return (result);
}