#include "tests.h"

int	main(void)
{
	char	inputs[] = "0123456789";
	int		limit;
	int		input;
	int		index;

	index = 0;
	limit = sizeof(inputs) - 1;
	while (index < limit)
	{
		input = (int) inputs[index];
		if (input != ft_toupper(input))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
