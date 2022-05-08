#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*result;
	char	byte;

	result = NULL;
	byte = (char) c;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			result = &s[index];
		index++;
	}
	if (c == '\0')
		return (&s[index]);
	return (result);
}
