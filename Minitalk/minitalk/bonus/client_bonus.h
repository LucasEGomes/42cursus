#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# define CLIENT_RESUME 0
# define CLIENT_WAIT   1
# define CLIENT_RESEND 2

typedef struct s_metadata
{
	int	last_signal_sent;
	int	status;
	int	process_id;
	unsigned char	value;
	int				index;
}	t_metadata;

#endif
