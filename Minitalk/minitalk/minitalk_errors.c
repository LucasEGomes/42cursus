#include "minitalk_errors.h"
#include "ft_print.h"
#include <unistd.h>

int	failed_to_initialize_server(void)
{
	ft_print_str(STDOUT_FILENO, ERROR_FAILED_TO_ALLOCATE_MEMORY);
	return (1);
}
