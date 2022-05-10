#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	number[12];
	int		digits;
	int		is_negative;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	digits = 11;
	number[digits] = '\0';
	while (digits > 0 + is_negative)
	{
		digits--;
		number[digits] = "0123456789"[(n % 10) * (-1 * is_negative)];
	}
	if (is_negative)
		number[digits] = '-';
	ft_putstr_fd(number + digits, fd);
}