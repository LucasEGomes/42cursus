#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;
	size_t	total;

	if (nmemb == 0 | size == 0)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	total = nmemb * size;
	result = malloc(sizeof(*result) * total);
	if (result == NULL)
		return (NULL);
	while (total > 0)
	{
		total--;
		result[total] = 0;
	}
	return (result);
}
