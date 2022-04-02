#include <unistd.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int	number;

	number = 0;
	ft_ft(&number);
	if (number == 42)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}