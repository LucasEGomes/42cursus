#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	total;
	char	*new_string;

	size1 = ft_strlen(s1);
	total = size1 + ft_strlen(s2) + 1;
	new_string = malloc(sizeof(*new_string) * total);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s1, size1);
	return ft_strlcat(new_string, s2, total);
}

