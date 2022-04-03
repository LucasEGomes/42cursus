#include "ex16.h"

int	main(void)
{
	run("", 0);
	run("\0Don't count me D:", 0);
	run("Omae wa mou shindeiru\0Nani!!!", 21);
}
