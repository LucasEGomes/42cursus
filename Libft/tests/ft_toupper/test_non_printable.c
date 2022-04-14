#include "tests.h"

int	main(void)
{
	int	inputs[33];
	int	limit;
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
	limit = sizeof(inputs) / sizeof(*inputs);
	while (index < limit)
	{
		input = inputs[index];
		if (input != ft_toupper(input))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
