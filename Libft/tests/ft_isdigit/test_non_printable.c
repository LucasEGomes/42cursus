#include "tests.h"

int	main(void)
{
	int	inputs[33];
	int	input;
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
		input = inputs[index];
		if (ft_isdigit(input) != 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
