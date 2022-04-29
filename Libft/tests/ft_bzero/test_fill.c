#include "tests.h"

#define CASES 4

int	main(void)
{
	char	*inputs[] = {
		"@@@@@@@@@@",
		"AAAAAAAAAA",
		"AAAAA",
		"ZZZZZZZ"
	};
	size_t	sizes[] = {10, 6, 5, 2};
	char	*targets[] = {
		"\0\0\0\0\0\0\0\0\0\0",
		"\0\0\0\0\0\0AAAA",
		"\0\0\0\0\0",
		"\0\0ZZZZZ"
	};
	void	*memory;
	void	*result;
	int		index;

	index = 0;
	while (index < CASES)
	{
		memory = strdup(inputs[index]);
		result = ft_bzero(memory, sizes[index]);
		if ((memory != result) ||
			(memcmp(targets[index], result, sizes[index] + 1) != 0))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
