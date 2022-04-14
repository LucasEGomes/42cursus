#include "tests.h"

int	main(void)
{
	char	inputs[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	targets[] = "abcdefghijklmnopqrstuvwxyz";
	int		limit;
	int		input;
	int		target;
	int		index;

	index = 0;
	limit = sizeof(inputs) - 1;
	while (index < limit)
	{
		input = (int) inputs[index];
		target = (int) targets[index];
		if (target != ft_tolower(input))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
