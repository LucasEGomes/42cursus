#include "ex14.h"
#include <limits.h>

int	main(void)
{
	run(0, 0);
	run(INT_MAX, 0);
	run(INT_MIN, 0);
	run(2147395600, 46340);
	run(2147395601, 0);
}
