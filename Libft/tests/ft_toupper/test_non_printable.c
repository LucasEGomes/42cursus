#include "tests.h"

int	main(void)
{
	int	inputs[33];
	int	index;

	index = 0;
	while (index < 32)
	{
		inputs[index] = index;
		index++;
	}
	inputs[index] = 127;
	index = 0;
	while (index < 33)
	{
		if (inputs[index] != ft_toupper(inputs[index]))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
