#include "ft_abs.h"
#include <unistd.h>

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
	run(42, 42);
	run(-42, 42);
	run(0, 0);
}
