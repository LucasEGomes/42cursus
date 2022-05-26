/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:23:25 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/25 12:43:05 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

void	*free_lines(char **lines)
{
	ssize_t	line;

	line = 0;
	while (lines[line] != NULL)
	{
		free(lines[line]);
		line++;
	}
	free(lines);
	return (NULL);
}

char	**alloc_lines(char *text)
{
	ssize_t	count;
	ssize_t	index;
	char	**lines;

	index = 0;
	count = 0;
	while (text[index] != '\0')
	{
		if (text[index] == '\n')
			count++;
		index++;
	}
	if (text[index - 1] != '\n')
		count++;
	lines = malloc(sizeof(*lines) * (count + 1));
	if (lines == NULL)
		return (NULL);
	lines[count] = NULL;
	return (lines);
}

char	**get_lines(char *text)
{
	ssize_t	index;
	ssize_t	line;
	char	**lines;

	lines = alloc_lines(text);
	if (lines == NULL)
		return (NULL);
	index = 0;
	line = 0;
	while (text[index] != '\0')
	{
		if (text[index] == '\n')
		{
			lines[line] = ft_substr(text, 0, index + 1);
			if (lines[line] == NULL)
				return (free_lines(lines));
			if (lines[line][index] == '\n' && lines[line][index - 1] == '$')
			{
				lines[line][index - 1] = '\n';
				lines[line][index] = '\0';
			}
			else if (lines[line][index] == '$')
				lines[line][index] = '\n';
			text += index + 1;
			index = 0;
			line += 1;
		}
		index++;
	}
	if (index > 0)
	{
		lines[line] = ft_substr(text, 0, index + 1);
		if (lines[line] == NULL)
			return (free_lines(lines));
		if (lines[line][index - 1] == '\n' && lines[line][index - 2] == '$')
		{
			lines[line][index - 2] = '\n';
			lines[line][index - 1] = '\0';
		}
		else if (lines[line][index - 1] == '$')
			lines[line][index - 1] = '\n';
	}
	return (lines);
}

int	check_line_length(char *value, char *expected, ssize_t line, int logger)
{
	size_t	value_len;
	size_t	expected_len;

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

int	test_whole_file(int file_descriptor, char **expected, int logger)
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
	failed += check_end_of_file(file_descriptor, logger);
	return (failed != 0);
}

void	print_message(char *filename, int result)
{
	char	*message;

	message = FG_GREEN "\t%s-OK\n" FG_RESET;
	if (result < 0)
		message = FG_YELLOW "\t%s-SKIP\n" FG_RESET;
	if (result > 0)
		message = FG_RED "\t%s-KO\n" FG_RESET;
	printf(message, ft_strchr(filename, '/') + 1);
}

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
		logger = open(argv[3], O_WRONLY | O_CREAT);
	test_file = open(argv[1], O_RDONLY);
	print_message(argv[0], test_whole_file(test_file, expected, logger));
	free_lines(expected);
	close(test_file);
	close(logger);
	return (EXIT_SUCCESS);
}
