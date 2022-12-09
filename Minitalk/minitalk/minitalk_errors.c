#include "minitalk_errors.h"
#include "utils/ft_print.h"
#include <unistd.h>

int	failed_to_initialize_server(void)
{
	ft_print_str(STDOUT_FILENO, ERROR_FAILED_TO_ALLOCATE_MEMORY);
	return (1);
}

int	invalid_number_of_arguments(void)
{
	ft_print_str(STDOUT_FILENO, ERROR_INVALID_NUMBER_OF_ARGUMENTS);
	return (1);
}
