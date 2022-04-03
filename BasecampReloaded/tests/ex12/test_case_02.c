#include "ex12.h"
#include <limits.h>

int	main(void)
{
	run(0, 1);
	run(INT_MIN, 0);
	run(INT_MAX, 0);
	run(13, 0);
	run(123456789, 0);
	run(12, 479001600);
}
