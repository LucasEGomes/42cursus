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
	int	numbers_0[] = {-100, -50};
	int	numbers_1[] = {4, 2};
	int	numbers_2[] = {2, 4};
	int	numbers_3[] = {123456, 42};

	act(numbers_0[0], numbers_0[1]);
	act(numbers_1[0], numbers_1[1]);
	act(numbers_2[0], numbers_2[1]);
	act(numbers_3[0], numbers_3[1]);
}
