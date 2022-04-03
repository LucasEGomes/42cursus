#include "ex17.h"
#include <stdio.h>

void	run(char *string_0, char *string_1, int expected)
{
	int	result;

	result = ft_strcmp(string_0, string_1);
	if (expected == result || (expected < 0 && result < 0)
		|| (expected > 0 && result > 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
