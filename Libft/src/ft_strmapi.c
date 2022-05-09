#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped_string;
	size_t	index;

	mapped_string = malloc(sizeof(*mapped_string) * ft_strlen(s));
	if (mapped_string == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		mapped_string[index] = f(index, s[index]);
		index++;
	}
	mapped_string[index] = '\0';
	return (mapped_string);
}
