#ifndef MINITALK_ERRORS_H
# define MINITALK_ERRORS_H
# define ERROR_FAILED_TO_ALLOCATE_MEMORY "Error: Failed to initialize server.\
\nUnable to allocate necessary memory.\n"
# define ERROR_INVALID_NUMBER_OF_ARGUMENTS "Error: Invalid number of arguments.\
\n\tExpected 2 arguments: server PID and string to be sent.\n"

int	failed_to_initialize_server(void);
int	invalid_number_of_arguments(void);

#endif
