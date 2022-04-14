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
		if (ft_isalnum(input) == 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
