#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# ifndef QUEUE_SIZE
#  define QUEUE_SIZE 4096
# endif
# include <unistd.h>

typedef struct s_server_metadata
{
	unsigned char	*content;
	size_t			content_index;
	int				bit_index;
	unsigned char	value;
}	t_server_metadata;

#endif
