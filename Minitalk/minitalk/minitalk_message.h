#ifndef MINITALK_MESSAGE_H
# define MINITALK_MESSAGE_H
# define BUFFER_SIZE 4096
# include <unistd.h>

typedef struct s_minitalk_message
{
	size_t			size;
	unsigned char	*content;
}	t_minitalk_message;

#endif
