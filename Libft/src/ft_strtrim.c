#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	index;

	index = 0;
	while (s1[index] != '\0' & ft_strchr(set, s1[index]) != NULL)
		index++;
	start = index;
	end = index;
	while (s1[index] != '\0')
	{
		if (ft_strchr(set, s1[index]) == NULL)
			end = index;
		index++;
	}
	return (ft_substr(s1, start, end - start));
}
