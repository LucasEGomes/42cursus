#include "tests.h"

int	main(void)
{
	int	inputs[15];
	int	limit;
	int	input;
	int	index;

	inputs[0] = 128;
	inputs[1] = -1 - '0';
	inputs[2] = -1 - '9';
	inputs[3] = -1 - 'a';
	inputs[4] = -1 - 'z';
	inputs[5] = -1 - 'A';
	inputs[6] = -1 - 'Z';
	inputs[7] = 128 + '0';
	inputs[8] = 128 + '9';
	inputs[9] = 128 + 'a';
	inputs[10] = 128 + 'z';
	inputs[11] = 128 + 'A';
	inputs[12] = 128 + 'Z';
	inputs[13] = 255;
	inputs[14] = 1024;
	index = 0;
	limit = sizeof(inputs) / sizeof(*inputs);
	while (index < limit)
	{
		input = inputs[index];
		if (ft_isprint(input) != 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
