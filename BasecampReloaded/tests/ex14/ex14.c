#include "ex14.h"

void	run(int number, int expected)
{
	int	result;
	clock_t	duration;

	duration = clock();
	result = ft_sqrt(number);
	duration = (clock() - duration);
	if (expected == result && TIMEOUT >= duration)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
