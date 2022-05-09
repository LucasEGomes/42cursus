#include "libft.h"

char	*ft_itoa(int n)
{
	char	*number;
	int		digits;
	int		temp;
	int		is_negative;

	digits = 1;
	temp = n;
	while (temp > 9)
	{
		temp /= 10;
		digits++;
	}
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		digits++;
	}
	number = malloc(sizeof(*number) * (digits + 1));
	number[digits] = '\0';
	while (digits > 0 + is_negative)
	{
		digits--;
		number[digits] = "0123456789"[(n % 10) * (-1 * is_negative)];
	}
	if (is_negative)
		number[0] = '-';
	return (number);
}
