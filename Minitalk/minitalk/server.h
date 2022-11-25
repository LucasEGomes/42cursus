#ifndef SERVER_H
# define SERVER_H
# define QUEUE_SIZE 4096
# include <unistd.h>

typedef struct s_deque
{
	void	*content;
	size_t	first;
	size_t	last;
}	t_deque;

#endif
