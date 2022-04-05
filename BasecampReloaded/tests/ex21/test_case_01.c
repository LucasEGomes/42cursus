#include "ex21.h"

int	g_fake = 0;

int	main(void)
{
	int	expected_0[] = {-100, -99, -98, -97};
	int	expected_1[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	run(42, 10, NULL);
	run(-100, -96, expected_0);
	run(-4, 10, expected_1);
}
