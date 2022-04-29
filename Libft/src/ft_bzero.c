#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*aux;

	aux = s;
	while (n > 0)
	{
		n--;
		aux[n] = 0;
	}
	return (s);
}
