/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:23:25 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/05 21:10:27 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

int	main(int argc, char **argv)
{
	int		logger;
	int		test_file;
	char	**expected;

	if (argc != 4)
		return (EXIT_FAILURE);
	logger = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
	expected = get_lines(argv[3]);
	if (expected == NULL)
		return (-1);
	test_file = open(argv[2], O_RDONLY);
	dprintf(1, "\t");
	print_message(argv[2], test_whole_file(test_file, expected, logger));
	close(test_file);
	dprintf(1, " | ");
	print_message("STDIN", test_read_standard_input(argv[2], expected, logger));
	free_lines(expected);
	close(logger);
	return (EXIT_SUCCESS);
}
