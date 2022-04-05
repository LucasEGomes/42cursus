#include "ft_abs.h"
#include <unistd.h>
#include <limits.h>

void	run(int number, int expected)
{
	(void) number;
	int result;

	result = ABS(number);
	if (result == expected)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(void)
{
	run(INT_MAX, INT_MAX);
	run(INT_MIN, INT_MIN);
	run(-INT_MAX, INT_MAX);
	run(1, 1);
	run(-1, 1);
}
