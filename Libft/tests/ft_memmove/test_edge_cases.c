#include "tests.h"

int	main(void)
{
	void	*sources[] = {
		"Hello There",
		"General Kenobi",
		"The quick brown fox\0jumps over the lazy dog."
	};
	size_t	sizes[] = {0, 1, 0};
	void	*targets[] = {
		"\0",
		"G\0",
		"\0"
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
		result = ft_memmove(destiny, sources[index], sizes[index]);
		if ((result != destiny) || memcmp(targets[index], result, sizes[index] + 1))
			return (EXIT_FAILURE);
		free(destiny);
		index++;
	}

}
