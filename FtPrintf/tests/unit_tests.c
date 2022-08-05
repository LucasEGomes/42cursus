/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:46:36 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/04 22:49:48 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

int	main(int argc, char **argv)
{
	int	result;

	if (argc != 3)
		return (EXIT_FAILURE);
	open_report_file(argv[1]);
	open_log_file(argv[2]);
	result = 1;
	result &= test_conversions();
	close_files();
	if (result == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
