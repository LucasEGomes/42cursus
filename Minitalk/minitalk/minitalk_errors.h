#ifndef MINITALK_ERRORS_H
# define MINITALK_ERRORS_H
# define ERROR_FAILED_TO_ALLOCATE_MEMORY "Error: Failed to initialize server.\
\nUnable to allocate necessary memory.\n"
# define ERROR_INVALID_NUMBER_OF_ARGUMENTS "Error: Invalid number of arguments.\
\n\tExpected 2 arguments: server PID and string to be sent.\n"

int		failed_to_initialize_server(void);
int		invalid_number_of_arguments(void);
void	failed_to_send_signal_to_server(int process_id);
void	failed_to_acquire_acknowledge_from_server(int process_id);

#endif
