#ifndef SERVER_H
# define SERVER_H
// 512 characters * 5
# define QUEUE_SIZE 2560
# define ERROR_FAILED_TO_ALLOCATE_MEMORY "Error: Failed to initialize server.\
\nUnable to allocate necessary memory."
# include <unistd.h>

typedef struct s_deque
{
	unsigned char	*content;
	size_t	first;
	size_t	last;
}	t_deque;

#endif
