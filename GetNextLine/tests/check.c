/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:00:56 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/04 18:08:16 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_line_length(char *value, char *expected, ssize_t line, int logger)
{
	size_t	value_len;
	size_t	expected_len;

	if (value == NULL)
		return (1);
	value_len = ft_strlen(value);
	expected_len = ft_strlen(expected);
	if(value_len == expected_len)
		return (0);
	dprintf(logger, \
		"FAILED: Lines length do not match at line %ld. " \
		"Expected `%lu` bytes. Found `%lu`\n", \
		line + 1, expected_len, value_len);
	return (1);
}

int	check_content(char *value, char *expected, ssize_t line, int logger)
{
	size_t	size;

	if (value == NULL)
		return (1);
	size = ft_strlen(expected);
	if(ft_strncmp(value, expected, size) == 0)
		return (0);
	dprintf(logger, \
		"FAILED: Lines content don't match at line %ld.\n"\
		"Expected: %s\n   Found: %s\n", \
		line + 1, expected, value);
	return (1);
}

int	check_end_of_file(int file_descriptor, int logger)
{
	char	*value;
	int		tries;

	tries = 0;
	while (tries < 3)
	{
		value = get_next_line(file_descriptor);
		if (value != NULL)
		{
			dprintf(logger, \
				"FAILED: All file was read. "\
				"Expected `NULL`. Found `%s`\n", value);
			free(value);
			return (1);
		}
		tries++;
	}
	return (0);
}

int	check_all_content(int file_descriptor, char **expected, int logger)
{
	ssize_t	line;
	char	*value;
	int		failed;

	failed = 0;
	line = 0;
	while (expected[line] != NULL)
	{
		value = get_next_line(file_descriptor);
		if (value == NULL)
		{
			dprintf(logger, \
				"SKIP: Failed to alloc memory at `get_next_line`.\n");
			return (-1);
		}
		failed += check_line_length(value, expected[line], line, logger);
		failed += check_content(value, expected[line], line, logger);
		free(value);
		line++;
	}
	return (failed != 0);
}

int	test_whole_file(int file_descriptor, char **expected, int logger)
{
	int		failed;

	failed = 0;
	failed += check_all_content(file_descriptor, expected, logger);
	if (failed == -1)
		return (-1);
	failed += check_end_of_file(file_descriptor, logger);
	return (failed != 0);
}

int	test_read_standard_input(char *filename, char **expected, int logger)
{
	int		file_descriptor;
	int		failed;
	
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor < 0)
		return (-1);
	dup2(file_descriptor, STDIN_FILENO);
	failed = 0;
	failed += test_whole_file(STDIN_FILENO, expected, logger);
	close(file_descriptor);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor < 0)
		return (-1);
	dup2(file_descriptor, STDIN_FILENO);
	failed += check_all_content(STDIN_FILENO, expected, logger);
	close(file_descriptor);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor < 0)
		return (-1);
	dup2(file_descriptor, STDIN_FILENO);
	failed += test_whole_file(STDIN_FILENO, expected, logger);
	close(file_descriptor);
	return (failed);
}