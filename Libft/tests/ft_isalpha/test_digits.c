#include "tests.h"

int	main(void)
{
	const char	*inputs = "0123456789";
	int			input;
	int			index;

	index = 0;
	while (index < 10)
	{
		input = (int) inputs[index];
		if (ft_isalpha(input) != 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
