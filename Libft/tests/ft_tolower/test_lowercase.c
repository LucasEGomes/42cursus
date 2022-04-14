#include "tests.h"

int	main(void)
{
	char	inputs[] = "abcdefghijklmnopqrstuvwxyz";
	int		limit;
	int		input;
	int		index;

	index = 0;
	limit = sizeof(inputs) - 1;
	while (index < limit)
	{
		input = (int) inputs[index];
		if (input != ft_tolower(input))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}

