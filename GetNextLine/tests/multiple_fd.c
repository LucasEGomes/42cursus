/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 00:14:29 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/04 18:19:27 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	int	file_descriptor_0;
	int	file_descriptor_1;
	int	logger;
	char	**expected_0;
	char	**expected_1;
	int		line_0;
	int		line_1;
	char	*value;
	int		failed;

	(void) argc;
	file_descriptor_0 = open(argv[2], O_RDONLY);
	file_descriptor_1 = open(argv[4], O_RDONLY);
	logger = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	expected_0 = get_lines(argv[3]);
	expected_1 = get_lines(argv[5]);
	line_0 = 0;
	line_1 = 0;
	failed = 0;
	dprintf(1, "\t");
	while (expected_0[line_0] != NULL && expected_1[line_1] != NULL)
	{
		if (expected_0[line_0] != NULL)
		{
			value = get_next_line(file_descriptor_0);
			if (value == NULL)
			{
				dprintf(logger, 
					"SKIP: Failed to alloc memory at `get_next_line`.\n");
				close(file_descriptor_0);
				close(file_descriptor_1);
				close(logger);
				free_lines(expected_0);
				free_lines(expected_1);
				print_message(argv[0], -1);
				return (0);
			}
			failed += check_content(value, expected_0[line_0], line_0 + 1, logger);
			free(value);
			line_0++;
		}
		if (expected_1[line_1] != NULL)
		{
			value = get_next_line(file_descriptor_1);
			if (value == NULL)
			{
				dprintf(logger, 
					"SKIP: Failed to alloc memory at `get_next_line`.\n");
				close(file_descriptor_0);
				close(file_descriptor_1);
				close(logger);
				free_lines(expected_0);
				free_lines(expected_1);
				print_message(argv[0], -1);
				return (0);
			}
			failed += check_content(value, expected_1[line_1], line_1 + 1, logger);
			free(value);
			line_1++;
		}
	}
	failed += check_end_of_file(file_descriptor_0, logger);
	failed += check_end_of_file(file_descriptor_1, logger);
	print_message(argv[0], failed);
	close(file_descriptor_0);
	close(file_descriptor_1);
	close(logger);
	free_lines(expected_0);
	free_lines(expected_1);
	return (EXIT_SUCCESS);
}
