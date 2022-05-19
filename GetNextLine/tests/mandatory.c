/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:23:25 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/18 22:52:16 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

int	setup(char *file)
{
	int	file_descriptor;

	file_descriptor = open(file, O_RDONLY);
	if (read(file_descriptor, NULL, 0) < 0)
		return (-1);
	return (file_descriptor);
}

int	tear_down(int file_descriptor)
{
	return (close(file_descriptor));
}

int	log_test(int test_number, char *file, int (*test)(int))
{
	int	fd;
	int	result;

	fd = setup(file);
	if (fd < 0)
		return (-1);
	result = test(fd);
	if (result)
		printf("\e[32m%d-OK\e[0m ", test_number);
	else
		printf("\e[31m%d-KO\e[0m ", test_number);
	tear_down(fd);
	return (result);
}

int	test_first_line(int fd)
{
	char	*value;
	char	*expected;
	int		result;

	expected = "Alice was beginning to get very tired of sitting by her sister\n";
	value = get_next_line(fd);
	if (value == NULL)
		return (0);
	result = memcmp(value, expected, 64) == 0;
	free(value);
	return (result);
}

int	test_second_line(int fd)
{
	char	*value;
	char	*expected;
	int		result;

	expected = "on the bank, and of having nothing to do:  once or twice she had\n";
	free(get_next_line(fd));
	value = get_next_line(fd);
	if (value == NULL)
		return (0);
	result = memcmp(value, expected, 66) == 0;
	free(value);
	return (result);
}

int	test_nothing_to_be_read(int fd)
{
	int		lines;
	char	*value;
	int		result;

	lines = 5 + 1;
	while (lines > 0)
	{
		free(get_next_line(fd));
		lines--;
	}
	value = get_next_line(fd);
	result = value == NULL;
	free(value);
	return(result);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	
	log_test(1, argv[1], test_first_line);
	log_test(2, argv[1], test_second_line);
	log_test(3, argv[1], test_nothing_to_be_read);
	printf("\n");
	return (EXIT_SUCCESS);
}
