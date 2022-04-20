#ifndef TESTS_H
# define TESTS_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_test_memset
{
	void	*s;
	int		c;
	size_t	n;
	size_t	size;
}	t_test_memset;

int	invalid_argument_error(char *message);

#endif
