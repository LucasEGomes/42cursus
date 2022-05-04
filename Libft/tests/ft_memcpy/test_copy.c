#include "tests.h"

int	main(void)
{
	void	*sources[] = {
		"Hello There",
		"General Kenobi",
		"The quick brown fox\0jumps over the lazy dog."
	};
	size_t	sizes[] = {12, 9, 45};
	void	*targets[] = {
		"Hello There\0",
		"General K\0",
		"The quick brown fox\0jumps over the lazy dog.\0"
	};
	int		index;
	void	*destiny;
	void	*result;

	index = 0;
	while (index < 3)
	{
		destiny = calloc(1, sizes[index] + 1);
		if (destiny == NULL)
			return (log_error("Failed to allocate memory to test."));
		result = ft_memcpy(destiny, sources[index], sizes[index]);
		if ((result != destiny) || memcmp(targets[index], result, sizes[index]))
			return (EXIT_FAILURE);
		free(destiny);
		index++;
	}

}
