#include <unistd.h>

void	ft_write(int fd, const void *buffer, size_t size)
{
	(void) (write(fd, buffer, size) & 1);
}
