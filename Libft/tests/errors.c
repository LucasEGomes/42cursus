#include "tests.h"

int	log_error(char *message)
{
	dprintf(STDERR_FILENO, "%s", message);
	return (EXIT_FAILURE);
}
