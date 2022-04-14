#include "tests.h"

int	main(void)
{
	const char	*inputs = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int			input;
	int			index;

	index = 0;
	while (index < 26)
	{
		input = (int) inputs[index];
		if (ft_isalnum(input) == 0)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
