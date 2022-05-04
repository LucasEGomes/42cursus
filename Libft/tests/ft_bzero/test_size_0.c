#include "tests.h"

int	main(void)
{
	char	*inputs[] = {
		"Hello There",
		"General Kenobi",
	};
	size_t	sizes[] = {12, 15};
	char	*targets[] = {
		"Hello There\0",
		"General Kenobi\0",
	};
	void	*memory;
	void	*result;
	int		index;

	index = 0;
	while (index < 2)
	{
		memory = strdup(inputs[index]);
		result = ft_bzero(memory, 0);
		if ((memory != result) ||
			(memcmp(targets[index], result, sizes[index]) != 0))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
