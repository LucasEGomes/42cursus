#include "tests.h"

int	main(void)
{
	char	*inputs[] = {"Hello There.", "General Kenobi!", 0};
	size_t	results[] = {12, 15};
	int		index;

	index = 0;
	while (inputs[index] != 0)
	{
		if (ft_strlen(inputs[index]) != results[index])
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
