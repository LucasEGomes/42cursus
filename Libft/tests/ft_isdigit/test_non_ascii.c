#include "tests.h"

int	main(void)
{
	int	inputs[7];
	int	input;
	int	index;

	inputs[0] = 128;
	inputs[1] = -1 - '0';
	inputs[2] = -1 - '9';
	inputs[3] = 128 + '0';
	inputs[4] = 128 + '9';
	inputs[5] = 255;
	inputs[6] = 1024;
	index = 0;
	while (index < 7)
	{
		input = inputs[index];
		if (ft_isdigit(input) != 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
