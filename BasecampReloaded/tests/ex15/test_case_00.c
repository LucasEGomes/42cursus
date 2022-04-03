#include "ex15.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_putstr("Hello There\n");
	ft_putstr("General Kenobi!");
}
