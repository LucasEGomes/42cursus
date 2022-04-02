#include <unistd.h>

void	ft_ft(int *nbr);

void	act(int	*number)
{
	ft_ft(number);
	if (*number == 42)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(void)
{
	int	number_0;
	int	number_1;
	int	number_2;
	int	*pointer_0;

	number_0 = -12345;
	pointer_0 = &number_2;
	act(&number_0);
	act(&number_1);
	act(pointer_0);
}
