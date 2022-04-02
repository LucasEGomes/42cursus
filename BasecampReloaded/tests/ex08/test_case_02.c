#include "ex08.h"
#include <limits.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_is_negative(-42);
	ft_is_negative(-1);
	ft_is_negative(INT_MIN);
	ft_is_negative(-12362);
}
