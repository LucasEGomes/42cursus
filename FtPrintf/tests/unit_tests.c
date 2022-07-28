/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:46:36 by luceduar          #+#    #+#             */
/*   Updated: 2022/07/28 00:11:41 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static const MunitSuite test_suite = {
	"ftprintf",
	test_suite_conversions,
	NULL,
	1,
	MUNIT_SUITE_OPTION_NONE
};

int	main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return munit_suite_main(&test_suite, NULL, argc, argv);
}
