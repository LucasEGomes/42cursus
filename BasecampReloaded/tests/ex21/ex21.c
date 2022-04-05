#include "ex21.h"
#ifndef NUMBERS
# define NUMBERS "0123456789"
#endif

extern int	g_fake;

static void	ft_putnbr(size_t number)
{
	const int	max_digits = 21;
	char		digits[max_digits];
	int			index;

	if (number == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (number == ULONG_MAX)
	{
		write(1, "18446744073709551616", 20);
		return ;
	}
	index = max_digits - 1;
	digits[index] = '\0';
	index--;
	while (number > 0)
	{
		digits[index] = NUMBERS[number % 10];
		number /= 10;
		index--;
	}
	index++;
	write(1, &digits[index], max_digits - index - 1);
}

void	*__wrap_malloc(size_t size)
{
	ft_putnbr(size / sizeof(int));
	write(1, "|", 1);
	if (g_fake)
		return (NULL);
	return (__real_malloc(size));
}

void	run(int min, int max, int *expected)
{
	int	*result;
	int	i;
	int	size;

	result = ft_range(min, max);
	if (expected == NULL)
	{
		if (expected != result)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
		return ;
	}
	i = 0;
	size = max - min;
	while (i < size)
	{
		if (expected[i] != result[i])
		{
			write(1, "KO\n", 3);
			return ;
		}
		i++;
	}
	write(1, "OK\n", 3);
}
