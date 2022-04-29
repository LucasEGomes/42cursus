#include "tests.h"

int	main(void)
{
	char	inputs[] = "abcdefghijklmnopqrstuvwxyz";
	char	targets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
		if (strcmp(target, ft_toupper(input)))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
