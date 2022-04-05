#include "ex21.h"

int	g_fake = 0;

int	main(void)
{
	int	expected_0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	expected_1[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	
	run(0, 10, expected_0);
	run(4, 17, expected_1);
}
