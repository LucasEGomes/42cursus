#include "tests.h"

int	main(void)
{
	char	inputs[] = " !\"#$\%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	int		index;

	index = 0;
	while (index < 34)
	{
		if ((int) inputs[index] != ft_toupper(inputs[index]))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
