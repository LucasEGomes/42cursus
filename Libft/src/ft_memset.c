#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*aux;

	aux = s;
	while (n > 0)
	{
		n--;
		aux[n] = c;
	}
	return (s);
}
