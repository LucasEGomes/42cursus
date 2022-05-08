#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*str_dest;
	const unsigned char	*str_src;
	size_t				index;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	index = 0;
	str_dest = dest;
	str_src = src;
	while (index < n)
	{
		str_dest[index] = str_src[index];
		index++;
	}
	return (dest);
}