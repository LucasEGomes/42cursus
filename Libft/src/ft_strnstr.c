#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		index;
	const char	temp;
	
	while (big[index] != '\0' & index < len)
	{
		index = 0;
		while (big[index] == little[index])
			index++;
		if (little[index == '\0'])
			return (big);
		big++;
	}
	return (NULL);
}
