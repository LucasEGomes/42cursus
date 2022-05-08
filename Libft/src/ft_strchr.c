#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	c_as_char;

	index = 0;
	c_as_char = (char) c;
	while (s[index] != '\0' & s[index] != c_as_char)
		index++;
	if (s[index] == c)
		return (&s[index]);
	return (NULL);
}
