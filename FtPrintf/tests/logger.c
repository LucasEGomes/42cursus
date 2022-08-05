/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_message.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:14:29 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/02 23:43:20 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

#define MESSAGE(format) "%s: Expected `" format "` found `" format "`.\n"
typedef int (*assert_functions)();

int	g_log_file = STDERR_FILENO;
int	g_report_file = STDOUT_FILENO;

const char *messages[] = {
	MESSAGE("%p"),
	MESSAGE("%d"),
};

static int _create(char *file, int *fd)
{
	if (file == NULL)
		return (-1);
	*fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	return (*fd);
}

int	open_log_file(char *log_file)
{
	return (_create(log_file, &g_log_file));
}

int	open_report_file(char *report_file)
{
	return (_create(report_file, &g_report_file));
}

void	close_files(void)
{
	close(g_log_file);
	close(g_report_file);
}

static int	failure(const char *caller)
{
	dprintf(g_report_file,
		"%-*s[" BOLD FG_RED " FAILED " NORMAL "]\n",
		TERMINAL_WIDTH - 10, caller);
	return (1);
}

static int	success(const char *caller)
{
	dprintf(g_report_file,
		"%-*s[" BOLD FG_GREEN "   OK   " NORMAL "]\n",
		TERMINAL_WIDTH - 10, caller);
	return (0);
}

static int	eq_pointer(void *expected, void *found)
{
	return (expected == found);
}

static int	eq_int(int *expected, int *found)
{
	return (*expected == *found);
}

const assert_functions functions[] = {
	eq_pointer,
	eq_int
};

int assert(const char *caller, void *expected, void *found, ASSERT_TYPE type)
{
	if (!functions[type](expected, found))
	{
		dprintf(g_log_file, messages[type], caller, expected, found);
		return (failure(caller));
	}
	return (success(caller));
}
