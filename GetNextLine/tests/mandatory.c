/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:23:25 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/17 23:12:11 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

int	log_test(int test_number, int result)
{
	return (printf("%d-%s ", test_number, TEST_RESULT(result)));
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
	result = strncmp(value, expected, 64) == 0;
	free(value);
	return (result);
}

int	test_nothing_to_be_read(int fd)
{
	char	buffer[256];
	char	*value;
	char	*expected;

	expected = NULL;
	while (read(fd, buffer, 256) > 0);
		;
	value = get_next_line(fd);
	return(value == expected);
}

int	main(int argc, char **argv)
{
	int		file_descriptor;
	ssize_t	read_bytes;
	
	file_descriptor = 0;
	if (argc > 1)
		file_descriptor = open(argv[1], O_RDONLY);
	read_bytes = read(file_descriptor, NULL, 0);
	// printf("File opened. Fd: %d, Read: %ld.\n", file_descriptor, read_bytes);
	if (read_bytes >= 0)
	{
		log_test(1, test_first_line(file_descriptor));
		log_test(2, test_nothing_to_be_read(file_descriptor));
	}
	close(file_descriptor);
	printf("\n");
	// printf("File closed.\n");
	return (EXIT_SUCCESS);
}
