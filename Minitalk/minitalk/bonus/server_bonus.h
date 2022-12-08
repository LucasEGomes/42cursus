#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# ifndef QUEUE_SIZE
#  define QUEUE_SIZE 4096
# endif
# define ERROR_FAILED_TO_ALLOCATE_MEMORY "Error: Failed to initialize server.\
\nUnable to allocate necessary memory."
# include <unistd.h>

typedef struct s_deque
{
	unsigned char	*content;
	size_t			last;
	int				bit_index;
}	t_deque;

#endif
