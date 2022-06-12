/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:06:20 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/04 21:40:32 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_CHECK_H
# define GNL_CHECK_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

extern char	*get_next_line(int fd);
int	check_line_length(char *value, char *expected, ssize_t line, int logger);
int	check_content(char *value, char *expected, ssize_t line, int logger);
int	check_end_of_file(int file_descriptor, int logger);
int	check_all_content(int file_descriptor, char **expected, int logger);
int	test_whole_file(int file_descriptor, char **expected, int logger);
int	test_read_standard_input(char *filename, char **expected, int logger);

#endif