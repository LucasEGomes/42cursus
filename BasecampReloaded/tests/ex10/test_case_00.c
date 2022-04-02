#include <unistd.h>

void	ft_swap(int *a, int *b);

void	act(int	number_0, int number_1)
{
	int	old_number_0;
	int	old_number_1;
	
	old_number_0 = number_0;
	old_number_1 = number_1;
	ft_swap(&number_0, &number_1);
	if (old_number_0 == number_1 && old_number_1 == number_0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int main(void)
{
	int	numbers[] = {0, 1};

	act(numbers[0], numbers[1]);
}
