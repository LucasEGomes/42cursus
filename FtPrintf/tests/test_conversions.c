/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:29:29 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/04 23:53:57 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_conversions.h"

int	g_logger;

int	test_next_conversion(char *input, size_t index)
{
	char	*expected;
	char	*value;

	expected = input + index;
	if (*expected == '\0')
		expected = NULL;
	value = next_conversion(input);
	return (ASSERT_POINTER(expected, value));
}

int	test_print_signed_int(int input, int expected)
{
	int	value;
	
	value = print_signed_int(input);
	return (ASSERT_INT(expected, value));
}

int	test_print_char(char input, int expected)
{
	int	value;

	value = print_char(input);
	return (ASSERT_INT(expected, value));
}

int	test_print_percent_sign(int expected)
{
	int	value;

	value = print_percent_sign();
	return (ASSERT_INT(expected, value));
}

int	test_print_string(char *input, int expected)
{
	int	value;

	value = print_string(input);
	return (ASSERT_INT(expected, value));
}

int	test_conversions(void)
{
	int	result;

	result = 1;
	result &= test_next_conversion("%c", 0);
	result &= test_next_conversion("%s", 0);
	result &= test_next_conversion("%p", 0);
	result &= test_next_conversion("%d", 0);
	result &= test_next_conversion("%i", 0);
	result &= test_next_conversion("%u", 0);
	result &= test_next_conversion("%x", 0);
	result &= test_next_conversion("%X", 0);
	result &= test_next_conversion("%%", 0);
	result &= test_next_conversion("%A", 2);
	result &= test_next_conversion("Hello There %c", 12);
	result &= test_next_conversion("Hello There %z General %d Kenobi", 23);
	result &= test_print_signed_int(4242, 4);
	result &= test_print_signed_int(0, 1);
	result &= test_print_signed_int(-1, 2);
	result &= test_print_signed_int(1, 1);
	result &= test_print_signed_int(INT_MIN, 11);
	result &= test_print_signed_int(INT_MAX, 10);
	result &= test_print_char('a', 1);
	result &= test_print_char('~', 1);
	result &= test_print_percent_sign(1);
	result &= test_print_string("Hello There", 11);
	result &= test_print_string("General Kenobi", 14);
	result &= test_print_string("", 0);
	result &= test_print_string(NULL, 6);
	return (result);
}
