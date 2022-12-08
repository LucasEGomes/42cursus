#ifndef SERVER_H
# define SERVER_H
# ifndef QUEUE_SIZE
#  define QUEUE_SIZE 4096
# endif
# include <unistd.h>

typedef struct s_deque
{
	unsigned char	*content;
	size_t			last;
	int				bit_index;
}	t_deque;

#endif
