/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:06:33 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 00:17:36 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TESTS_H
# define UNIT_TESTS_H
# include "formats.h"
# include "logger.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef	struct s_params
{
	char	*input;
	ssize_t	index;
}	t_params;

extern int	test_conversions(void);
extern int	test_ft_printf_utils(void);

#endif
