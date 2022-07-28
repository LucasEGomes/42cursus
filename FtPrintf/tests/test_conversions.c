/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:29:29 by luceduar          #+#    #+#             */
/*   Updated: 2022/07/27 21:12:14 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_conversions.h"
#include <assert.h>

typedef struct s_is_conversion
{
	char	*input;
	char	index;
}	t_is_conversion;

t_is_conversion	is_conversion_data[] = {
	{"%c", 0},
	{"Hello There %c", 12},
	{"%z", 5},
	{"Hello There %z General %d Kenobi", 23}
};

t_is_conversion	*is_conversions_test_cases[] = {
	&is_conversion_data[0],
	&is_conversion_data[1],
	&is_conversion_data[2],
	&is_conversion_data[3],
	NULL
};

static MunitParameterEnum is_conversion_params[] = {
	{"is_conversion", (void *)is_conversions_test_cases},
	{NULL, NULL}
};

MunitResult test_is_conversion(const MunitParameter params[], void* data)
{
	ssize_t	index;
	t_is_conversion	*test_case;

	(void) data;
	test_case = (void *)munit_parameters_get(params, "is_conversion");
	index = 0;
	while (test_case->input[index] != '\0' &&
		!is_conversion(&test_case->input[index]))
		index++;
	munit_assert_int(test_case->index, ==, index);
	return (MUNIT_OK);
}

MunitTest test_suite_conversions[] = {
	{"/conversions", test_is_conversion, NULL, NULL, 0, is_conversion_params},
	{NULL, NULL, NULL, NULL, 0, NULL}
};
