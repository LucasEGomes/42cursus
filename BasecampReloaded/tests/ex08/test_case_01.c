#include "ex08.h"
#include <limits.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	(void) c;
}

int	main(void)
{
	ft_is_negative(42);
	ft_is_negative(0);
	ft_is_negative(INT_MAX);
	ft_is_negative(62123);
}
