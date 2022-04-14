#include "tests.h"

int	main(void)
{
	const char	*inputs = " !\"#$\%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	int			input;
	int			index;

	index = 0;
	while (index < 34)
	{
		input = (int) inputs[index];
		if (ft_isdigit(input) != 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
