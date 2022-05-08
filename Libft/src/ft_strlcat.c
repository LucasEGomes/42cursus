#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dst_size;

	index = 0;
	while (dst[index] != '\0' & index < size)
		index++;
	if (index == size)
		return (index);
	dst_size = index;
	index = 0;
	while (index < size - dst_size - 1)
	{
		dst[dst_size + index] = src[index];
		if (src[index] == '\0')
			return (index + dst_size);
		index++;
	}
	return (size);
}
