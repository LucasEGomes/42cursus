#include "ex17.h"

int	main(void)
{
	run("Hello There", "General Kenobi", 1);
	run("General Kenobi", "General KenObi", 1);
	run("Hello There", "general Kenobi", -1);
	run("General Kenobi", "General kenobi", -1);
}
