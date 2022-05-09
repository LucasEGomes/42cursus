#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = s1;
	us2 = s2;
	while ((us1[i] == us2[i]) & (us1 != '\0') & (us2 != '\0') & (i < n - 1))
		i++;
	return (us1[i] - us2[i]);
}