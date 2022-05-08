#include "libft.h"

int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	size_t				index;
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = s1;
	us2 = s2;
	index = 0;
	while (us1[index] == us2[index] & index < n)
		index++;
	return (us1[index] - us2[index]);
}
