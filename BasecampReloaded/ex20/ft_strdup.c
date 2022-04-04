#include <stdlib.h>

static int	ft_strlen(char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*ft_strdup(char *src)
{
	int		index;
	char	*result;

	index = 0;
	result = malloc(sizeof(*result) * (ft_strlen(src) + 1));
	if (result == NULL)
		return (NULL);
	while (src[index] != '\0')
	{
		result[index] = src[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
