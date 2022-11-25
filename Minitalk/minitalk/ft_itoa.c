#include <stdlib.h>

static int	get_digits(int n)
{
	int	digits;
	int	temp;

	digits = 1;
	temp = n;
	while ((-9 > temp) | (temp > 9))
	{
		temp /= 10;
		digits++;
	}
	return (digits);
}

static int	absolute(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		digits;
	int		is_negative;

	digits = get_digits(n);
	is_negative = n < 0;
	number = malloc(sizeof(*number) * (digits + is_negative + 1));
	if (number == NULL)
		return (NULL);
	if (is_negative)
	{
		digits++;
		number[0] = '-';
	}
	number[digits] = '\0';
	while (digits > is_negative)
	{
		digits--;
		number[digits] = "0123456789"[absolute(n % 10)];
		n = n / 10;
	}
	return (number);
}
