#include "tests.h"

int	main(void)
{
	char	inputs[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	targets[] = "abcdefghijklmnopqrstuvwxyz";
	int		index;

	index = 0;
	while (index < 26)
	{
		if ((int) targets[index] != ft_tolower(inputs[index]))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
