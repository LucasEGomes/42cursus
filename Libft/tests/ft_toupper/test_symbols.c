#include "tests.h"

int	main(void)
{
	char	inputs[] = " !\"#$\%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	int		limit;
	int		input;
	int		index;

	index = 0;
	limit = sizeof(inputs) - 1;
	while (index < limit)
	{
		input = (int) inputs[index];
		if (!strcmp(input, ft_toupper(input)))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
