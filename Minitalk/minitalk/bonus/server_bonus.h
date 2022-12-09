#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# define QUEUE_SIZE 4096
# define TIMEOUT_USECONDS 1000000
# include <unistd.h>
# include <signal.h>

typedef struct s_server_metadata
{
	unsigned char	*content;
	size_t			content_index;
	int				bit_index;
}	t_server_metadata;

#endif
