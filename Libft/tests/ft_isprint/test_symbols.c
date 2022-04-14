#include "tests.h"

int	main(void)
{
	char	inputs[] = " !\"#$\%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	int		limit;
	int		input;
	int		index;

	limit = sizeof(inputs) - 1;
	index = 0;
	while (index < limit)
	{
		input = (int) inputs[index];
		if (ft_isprint(input) == 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
