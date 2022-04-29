#include "tests.h"

#define ARGS 5

int	main(int argc, char **argv)
{
	int		index;
	void	*memory;
	int		value;
	size_t	size;
	size_t	check_size;
	void	*target;
	void	*result;

	if (argc < ARGS + 1)
		return (invalid_argument_error("Insufficient arguments.\n"));
	if ((argc - 1) % ARGS != 0)
		return (invalid_argument_error("Wrong number of arguments.\n"));
	index = 1;
	while (index < argc)
	{
		memory = argv[index];
		value = (int) (argv[index + 1][0]);
		size = (size_t) atol(argv[index + 2]);
		target = argv[index + 3];
		check_size = (size_t) atol(argv[index + 4]) + 1;
		result = ft_memset(memory, value, size);
		if ((memory != result) || (memcmp(target, result, check_size) != 0))
			return (EXIT_FAILURE);
		index += ARGS;
	}
	return (EXIT_SUCCESS);
}
