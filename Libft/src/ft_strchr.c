#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	byte;

	index = 0;
	byte = (char) c;
	while (s[index] != '\0' & s[index] != byte)
		index++;
	if (s[index] == c)
		return (&s[index]);
	return (NULL);
}
