#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

void	ft_putnbr(int	n)
{
	char	c;

	c = (char) n + '0';
	write(1, &c, 1);
}

void	ft_nothing(int	n)
{
	(void) n;

	return ;
}

int	main(void)
{
	int	pi_100[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8,\
		4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9,\
		3, 9, 9, 3, 7, 5, 1, 0, 5, 8, 2, 0, 9, 7, 4, 9, 4, 4, 5, 9, 2, 3, 0, 7,\
		8, 1, 6, 4, 0, 6, 2, 8, 6, 2, 0, 8, 9, 9, 8, 6, 2, 8, 0, 3, 4, 8, 2, 5,\
		3, 4, 2, 1, 1, 7, 0, 6, 7, 9};
	
	ft_foreach(pi_100, 100, ft_putnbr);
	ft_foreach(pi_100, 5, ft_putnbr);
	ft_foreach(pi_100, 100, ft_nothing);
}