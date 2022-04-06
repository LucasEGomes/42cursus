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
	int	values_0[] = {0, 1, 2, 3, 4};
	int	values_1[] = {9, 7, 4, 2};
	
	ft_foreach(values_0, 5, ft_putnbr);
	ft_foreach(values_1, 4, ft_putnbr);
}