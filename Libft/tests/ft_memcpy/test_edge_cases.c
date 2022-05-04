#include "tests.h"

int	main(void)
{
	void	*sources[] = {
		"Hello There",
		"",
		""
	};
	size_t	sizes[] = {0, 1, 0};
	void	*targets[] = {
		"Hello There\0",
		"\0",
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
		result = ft_memcpy(destiny, sources[index], sizes[index]);
		if ((result != destiny) || memcmp(targets[index], result, sizes[index]))
			return (EXIT_FAILURE);
		free(destiny);
		index++;
	}

}
