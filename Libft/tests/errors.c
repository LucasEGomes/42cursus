#include "tests.h"

int	invalid_argument_error(char *message)
{
	dprintf(STDERR_FILENO, "%s", message);
	return (EXIT_FAILURE);
}
