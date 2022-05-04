#include "tests.h"

int	main(void)
{
	char	inputs[] = "abcdefghijklmnopqrstuvwxyz";
	char	targets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int		index;

	index = 0;
	while (index < 26)
	{
		if ((int) targets[index] != ft_toupper(inputs[index]))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
