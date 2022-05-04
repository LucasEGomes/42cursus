#include "tests.h"

int	main(void)
{
	char	*inputs[] = {
		"@@@@@@@@@@",
		"AAAAAAAAAA",
		"AAAAA",
		"ZZZZZZZ"
	};
	char	*chars = "aT[f";
	size_t	sizes[] = {10, 6, 5, 2};
	char	*targets[] = {
		"aaaaaaaaaa",
		"TTTTTTAAAA",
		"[[[[[",
		"ffZZZZZ"
	};
	void	*memory;
	void	*result;
	int		index;

	index = 0;
	while (index < 4)
	{
		memory = strdup(inputs[index]);
		result = ft_memset(memory, chars[index], sizes[index]);
		if ((memory != result) ||
			(memcmp(targets[index], result, sizes[index]) != 0))
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
