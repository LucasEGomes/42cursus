#include "tests.h"

int	main(void)
{
	char	*inputs[] = {"\0", "\0am I a empty string?", 0};
	size_t	results[] = {0, 0};
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
