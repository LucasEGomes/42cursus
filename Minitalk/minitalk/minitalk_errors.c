#include "minitalk_errors.h"
#include "utils/ft_print.h"
#include <unistd.h>
#include <stdlib.h>

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

void	failed_to_send_signal_to_server(int process_id)
{
	ft_print_str(STDOUT_FILENO,
		"ERROR: Failed to send signal to server at PID ");
	ft_print_int(STDOUT_FILENO, process_id);
	ft_print_str(STDOUT_FILENO, ". Stopping client...\n");
	exit(1);
}

void	failed_to_acquire_acknowledge_from_server(int process_id)
{
	ft_print_str(STDOUT_FILENO, "ERROR: Server at PID ");
	ft_print_int(STDOUT_FILENO, process_id);
	ft_print_str(STDOUT_FILENO,
		" did not return an acknowledge signal.\nStopping client...\n");
	exit(1);
}
