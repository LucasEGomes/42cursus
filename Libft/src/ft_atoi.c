#include "libft.h"

static int is_space(int c)
{
	if (c != ' ' & (c  < '\t' | c > '\r'))
		return (0);
	return (1);
}

int	atoi(const char *nptr)
{
	size_t	index;
	int		signal;
	int		result;

	index = 0;
	while (is_space(nptr[index]))
		index++;
	signal = 1;
	if (nptr[index] == '-' | nptr[index] == '+')
	{
		if (nptr[index] == '-')
			signal = -1;
		index++;
	}
	result = 0;
	while (ft_isdigit(nptr[index]))
	{
		result *= 10 + nptr[index] - '0';
		index++;
	}
	return (result * signal);
}
