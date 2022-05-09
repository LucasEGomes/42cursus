#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*duplicate;

	size = ft_strlen(s) + 1;
	duplicate = malloc(sizeof(*duplicate) * size);
	if (duplicate == NULL)
		return (NULL);
	while (size > 0)
	{
		duplicate[size] = s[size];
		size--;
	}
	duplicate[size] = s[size];
	return (duplicate);
}
