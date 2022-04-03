#include "ex15.h"

void	ft_putchar(char c)
{
	(void) c;
	write(1, "a", 1);
}

int	main(void)
{
	ft_putstr("Hello There\n");
	ft_putstr("General Kenobi!");
}
