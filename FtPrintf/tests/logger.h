/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_message.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:14:31 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/02 23:43:15 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# ifndef TERMINAL_WIDTH
#  define TERMINAL_WIDTH 60
#endif

# define SUCCESS success(__func__)
# define FAILURE failure(__func__)
typedef enum e_assert_type {TYPE_POINTER, TYPE_INT, TYPE_STRING} ASSERT_TYPE;
# define ASSERT_POINTER(expected, found) \
	assert(__func__, expected, found, TYPE_POINTER)
# define ASSERT_INT(expected, found) \
	assert(__func__, &expected, &found, TYPE_INT)
# define ASSERT_STRING(expected, found) \
	assert(__func__, expected, found, TYPE_STRING)


# include "formats.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>

int	open_log_file(char *log_file);
int	open_report_file(char *log_file);
void	close_files(void);
int assert(const char *caller, void *expected, void *found, ASSERT_TYPE type);

#endif
