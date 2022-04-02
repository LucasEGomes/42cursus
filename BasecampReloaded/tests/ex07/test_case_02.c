#include "ex07.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	(void) c;
	write(1, "a", 1);
}

int	main(void)
{
	ft_print_numbers();
}
