#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*us;
	unsigned char	uc;

	us = s;
	uc = c;
	index = 0;
	while (us[index] != uc & index < n - 1)
		index++;
	if (us[index] != uc)
		return (NULL);
	return (&s[index]);
}
