#ifndef SERVER_H
# define SERVER_H
// 512 characters * 8 bits
# define QUEUE_SIZE 4096
# define ERROR_FAILED_TO_ALLOCATE_MEMORY "Error: Failed to initialize server.\
\nUnable to allocate necessary memory."
# include <unistd.h>

typedef struct s_deque
{
	void	*content;
	size_t	first;
	size_t	last;
}	t_deque;

#endif
