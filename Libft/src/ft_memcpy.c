#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	const unsigned char	*str_src;

	str_dest = dest;
	str_src = src;
	while(n != 0)
	{
		n--;
		str_dest[n] = str_src[n];
	}
	return (dest);
}
