/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:23:52 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/28 21:20:09 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDATORY_H
# define MANDATORY_H
# include "src/get_next_line.h"
# include "libft/libft.h"
# include "colors.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
# define TEST_TEMP_FILE "test_temp"

int		check_line_length(char *value, char *expected, ssize_t line, int logger);
int		check_content(char *value, char *expected, ssize_t line, int logger);
int		check_end_of_file(int file_descriptor, int logger);
int		check_all_content(int file_descriptor, char **expected, int logger);
int		test_whole_file(int file_descriptor, char **expected, int logger);
int		test_read_standard_input(char *filename, char **expected, int logger);

void	*free_lines(char **lines);
char	**get_lines(char *text);
void	print_message(char *filename, int result);
#endif
