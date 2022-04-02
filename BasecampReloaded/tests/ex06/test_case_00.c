#include <unistd.h>
#include "ex06.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_print_alphabet();
}
