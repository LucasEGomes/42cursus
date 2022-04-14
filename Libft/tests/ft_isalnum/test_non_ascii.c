#include "tests.h"

int	main(void)
{
	int	inputs[11];
	int	input;
	int	index;

	inputs[0] = 128;
	inputs[1] = -1 - '0';
	inputs[2] = -1 - '9';
	inputs[2] = -1 - 'a';
	inputs[2] = -1 - 'z';
	inputs[2] = -1 - 'A';
	inputs[2] = -1 - 'Z';
	inputs[5] = 128 + '0';
	inputs[6] = 128 + '9';
	inputs[6] = 128 + 'a';
	inputs[6] = 128 + 'z';
	inputs[6] = 128 + 'A';
	inputs[6] = 128 + 'Z';
	inputs[9] = 255;
	inputs[10] = 1024;
	index = 0;
	while (index < 11)
	{
		input = inputs[index];
		if (ft_isalnum(input) != 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
