#include "tests.h"
#define OVER_UINT 4294967304UL

int	main(void)
{
	size_t	*inputs;
	size_t	index;
	size_t	result;

	inputs = malloc(OVER_UINT);
	index = 0;
	while (index < OVER_UINT / sizeof(*inputs))
	{
		inputs[index] = 0UL - 1;
		index++;
	}
	inputs[index - 1] = 0UL;
	result = ft_strlen((char *) inputs);
	free(inputs);
	if (result != OVER_UINT - 8)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
