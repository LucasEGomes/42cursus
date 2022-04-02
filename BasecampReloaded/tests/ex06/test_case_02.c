#include <unistd.h>
#include "ex06.h"

void	ft_putchar(char c)
{
	(void) c;
	write(1, "a", 1);
}

int	main(void)
{
	ft_print_alphabet();
}
