#include "tests.h"

int	main(void)
{
	int	inputs[11];
	int	input;
	int	index;

	inputs[0] = 128;
	inputs[1] = -1 - 'A';
	inputs[2] = -1 - 'Z';
	inputs[3] = -1 - 'a';
	inputs[4] = -1 - 'z';
	inputs[5] = 128 + 'A';
	inputs[6] = 128 + 'Z';
	inputs[7] = 128 + 'a';
	inputs[8] = 128 + 'z';
	inputs[9] = 255;
	inputs[10] = 1024;
	index = 0;
	while (index < 11)
	{
		input = inputs[index];
		if (ft_isalpha(input) != 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
