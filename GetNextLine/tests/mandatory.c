/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:23:25 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/28 22:34:39 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

int	main(int argc, char **argv)
{
	int		logger;
	int		test_file;
	char	**expected;

	if (argc < 3 || argc > 4)
		return (EXIT_FAILURE);
	expected = get_lines(argv[2]);
	if (expected == NULL)
		return (-1);
	logger = open("/dev/null", O_WRONLY);
	if (argc == 4)
		logger = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC);
	test_file = open(argv[1], O_RDONLY);
	printf("\t");
	print_message(argv[0], test_whole_file(test_file, expected, logger));
	close(test_file);
	printf(" | ");
	print_message("STDIN", test_read_standard_input(argv[1], expected, logger));
	free_lines(expected);
	close(logger);
	return (EXIT_SUCCESS);
}
