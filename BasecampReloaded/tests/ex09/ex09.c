#include "ex09.h"

void	run(int	*number)
{
	ft_ft(number);
	if (*number == 42)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
