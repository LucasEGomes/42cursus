#include "ex16.h"

void	run(char *string, int expected)
{
	if (expected == ft_strlen(string))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}