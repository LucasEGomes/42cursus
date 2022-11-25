#include <stdlib.h>

size_t	ft_strlen(char *string)
{
	size_t	size;

	size = 0;
	while (*string++ != '\0')
		size++;
	return (size);
}
