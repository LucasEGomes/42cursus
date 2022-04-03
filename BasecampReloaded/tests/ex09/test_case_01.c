#include "ex09.h"

int	main(void)
{
	int	number_0;
	int	number_1;
	int	number_2;
	int	*pointer_0;

	number_0 = -12345;
	pointer_0 = &number_2;
	run(&number_0);
	run(&number_1);
	run(pointer_0);
}
