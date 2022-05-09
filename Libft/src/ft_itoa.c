#include "libft.h"

char	*ft_itoa(int n)
{
	char	*number;
	int		digits;
	int		temp;

	digits = 1;
	temp = n;
	while (temp > 9)
	{
		temp /= 10;
		digits++;
	}
	number = malloc(sizeof(*number) * (digits + 1));
	number[digits] = '\0';
	while (digits > 0)
	{
		digits--;
		number[digits] = "0123456789"[n % 10];
	}
	return (number);
}
