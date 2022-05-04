#include "tests.h"

int	main(void)
{
	char	inputs[] = "0123456789";
	int		index;

	index = 0;
	while (index < 10)
	{
		if ((int) inputs[index] != ft_toupper(inputs[index]))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
