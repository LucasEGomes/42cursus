#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;

	sub_string = malloc(sizeof(*sub_string) * (len + 1));
	if (sub_string == NULL)
		return (NULL);
	return (ft_strlcpy(sub_string, s, len + 1));
}
