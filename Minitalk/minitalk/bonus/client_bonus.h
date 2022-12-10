#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# define CLIENT_RESUME 0
# define CLIENT_WAIT 1
# define RETRY_LIMIT 3
# define TIMEOUT 1000000
#include <signal.h>

typedef struct s_metadata
{
	pid_t	server_pid;
	int		status;
}	t_metadata;

#endif
