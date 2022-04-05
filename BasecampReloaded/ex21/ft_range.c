#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*result;
	unsigned int	size;
	unsigned int	index;

	if (min >= max)
		return (NULL);
	size = min + 1;
	size = max - size + 1;
	result = malloc(sizeof(*result) * ((size_t)size));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		result[index] = min + index;
		index++;
	}
	return (result);
}
