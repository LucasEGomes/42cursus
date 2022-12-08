#include "utils/ft_absolute.h"
#include "utils/ft_count_digits.h"
#include <stdlib.h>


char	*ft_itoa(int n)
{
	char	*number;
	int		digits;
	int		is_negative;

	digits = ft_count_digits_int(n, 10);
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
		number[digits] = ft_absolute_int(n % 10) + '0';
		n = n / 10;
	}
	return (number);
}
