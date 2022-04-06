#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

void	ft_putnbr(int	n)
{
	char	c;
	
	c = (char) n + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	values_0[] = {9, 7, 4, 2, 1, 3, 5, 8, 0, 6};
	int	values_1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	ft_foreach(values_0, -1, ft_putnbr);
	ft_foreach(values_0, 0, ft_putnbr);
	ft_foreach(values_0, 4, ft_putnbr);
	ft_foreach(values_1, 4, ft_putnbr);
	ft_foreach(values_1, -1, ft_putnbr);
}