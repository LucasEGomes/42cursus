#include "ex16.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	run("", 0);
	run(argv[1], 73935);
}
