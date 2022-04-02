#include "ex08.h"
#include <limits.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_is_negative(0);
	ft_is_negative(9);
	ft_is_negative(-1234567890);
	ft_is_negative(-123456789);
	ft_is_negative(-12345678);
	ft_is_negative(90);
	ft_is_negative(-1234567);
	ft_is_negative(890);
	ft_is_negative(7890);
	ft_is_negative(67890);
	ft_is_negative(567890);
	ft_is_negative(-123456);
	ft_is_negative(-12345);
	ft_is_negative(-1234);
	ft_is_negative(-123);
	ft_is_negative(-12);
	ft_is_negative(-1);
	ft_is_negative(1567890);
	ft_is_negative(41567890);
	ft_is_negative(241567890);
	ft_is_negative(2143567890);
}
