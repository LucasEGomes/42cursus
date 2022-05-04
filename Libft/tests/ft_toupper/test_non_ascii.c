#include "tests.h"

int	main(void)
{
	int	inputs[9];
	int	index;

	inputs[0] = 128;
	inputs[1] = -1;
	inputs[2] = 128 + '0';
	inputs[3] = 128 + '9';
	inputs[4] = 128 + 'a';
	inputs[5] = 128 + 'z';
	inputs[6] = 128 + 'A';
	inputs[7] = 128 + 'Z';
	inputs[8] = 255;
	index = 0;
	while (index < 9)
	{
		if (inputs[index] != ft_toupper(inputs[index]))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
