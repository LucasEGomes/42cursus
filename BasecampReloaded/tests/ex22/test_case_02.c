#include "ft_abs.h"
#include <unistd.h>
#include <limits.h>

void	run(long number, long expected)
{
	(void) number;
	long result;

	result = ABS(number);
	if (result == expected)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(void)
{
	run(42, 42);
	run(-42, 42);
	run(0, 0);
	run(LONG_MAX, LONG_MAX);
	run(LONG_MIN, LONG_MIN);
	run(-LONG_MAX, LONG_MAX);
	run(1, 1);
	run(-1, 1);
}
