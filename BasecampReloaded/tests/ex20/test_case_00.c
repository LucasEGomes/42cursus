#include "ex20.h"

void	*__wrap_malloc(size_t size)
{
	return (__real_malloc(size));
}

int	main(void)
{
	run("Hello There");
	run("General Kenobi");
}
