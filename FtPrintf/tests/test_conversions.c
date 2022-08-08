/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:29:29 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 02:37:40 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_conversions.h"

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

int	test_print_hexadecimal(unsigned int number, int is_upper, int expected)
{
	int	value;

	value = print_hexadecimal(number, is_upper);
	return (ASSERT_INT(expected, value));
}

int	suite_next_conversion(void)
{
	typedef struct s_data
	{
		char	*input;
		size_t	index;
	}	t_data;
	int	total;
	int	success;
	t_data test_cases[] = {
		{"%c", 0},
		{"%s", 0},
		{"%p", 0},
		{"%d", 0},
		{"%i", 0},
		{"%u", 0},
		{"%x", 0},
		{"%X", 0},
		{"%%", 0},
		{"%A", 2},
		{"Hello There %c", 12},
		{"Hello There %z General %d Kenobi", 23},
		{NULL, 0}
	};
	t_data	*test_case;

	total = 0;
	success = 0;
	test_case = test_cases;
	while (test_case->input != NULL && test_case->index != 0)
	{
		success += test_next_conversion(test_case->input, test_case->index);
		total++;
		test_case++;
	}
	return (total == success);
}

int	suite_print_signed_int(void)
{
	typedef struct s_data
	{
		int input;
		int	expected;
	}	t_data;
	int	total;
	int	success;
	t_data test_cases[] = {
		{4242, 4},
		{0, 1},
		{-1, 2},
		{1, 1},
		{INT_MIN, 11},
		{INT_MAX, 10},
		{0, 0}
	};
	t_data	*test_case;

	total = 0;
	success = 0;
	test_case = test_cases;
	while (test_case->input != 0 && test_case->expected != 0)
	{
		success += test_print_signed_int(test_case->input, test_case->expected);
		total++;
		test_case++;
	}
	return (total == success);
}

int	suite_print_char(void)
{
	typedef struct s_data
	{
		char	input;
		int		expected;
	}	t_data;
	int	total;
	int	success;
	t_data test_cases[] = {
		{'a', 1},
		{'~', 1},
		{0, 0}
	};
	t_data	*test_case;

	total = 0;
	success = 0;
	test_case = test_cases;
	while (test_case->input != 0 && test_case->expected != 0)
	{
		success += test_print_char(test_case->input, test_case->expected);
		total++;
		test_case++;
	}
	return (total == success);
}

int	suite_print_percent_sign(void)
{
	int	total;
	int	success;
	int test_cases[] = {1, 0};
	int	*test_case;

	total = 0;
	success = 0;
	test_case = test_cases;
	while (*test_case != 0)
	{
		success += test_print_percent_sign(*test_case);
		total++;
		test_case++;
	}
	return (total == success);
}

int	suite_print_string(void)
{
	typedef struct s_data
	{
		char	*input;
		int		expected;
	}	t_data;
	int	total;
	int	success;
	t_data test_cases[] = {
		{"Hello There", 11},
		{"General Kenobi", 14},
		{"", 0},
		{NULL, 6},
		{NULL, 0}
	};
	t_data	*test_case;

	total = 0;
	success = 0;
	test_case = test_cases;
	while (test_case->input != NULL && test_case->expected != 0)
	{
		success += test_print_string(test_case->input, test_case->expected);
		total++;
		test_case++;
	}
	return (total == success);
}

int	suite_print_hexadecimal(void)
{
	typedef struct s_data
	{
		unsigned int	number;
		int				is_upper;
		int				expected;
	}	t_data;
	int	total;
	int	success;
	t_data test_cases[] = {
		{42U, 1, 2},
		{0U, 1, 1},
		{4294967295U, 1, 8},
		{42U, 0, 2},
		{0, 0, 0}
	};
	t_data	*test_case;

	total = 0;
	success = 0;
	test_case = test_cases;
	while (test_case->number != 0 && test_case->is_upper != 0 && test_case->expected != 0)
	{
		success += test_print_hexadecimal(test_case->number, test_case->is_upper, test_case->expected);
		total++;
		test_case++;
	}
	return (total == success);
}


int	test_conversions(void)
{
	int	success;
	int	total;

	total = 0;
	success = 0;
	success += suite_next_conversion();
	total++;
	success += suite_print_signed_int();
	total++;
	success += suite_print_char();
	total++;
	success += suite_print_percent_sign();
	total++;
	success += suite_print_string();
	total++;
	success += suite_print_hexadecimal();
	total++;
	return (total == success);
}
