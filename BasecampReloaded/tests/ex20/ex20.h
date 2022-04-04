#ifndef EX20_H
# define EX20_H
# include <stdlib.h>
# include <unistd.h>

extern void	*__real_malloc();
char	*ft_strdup(char *src);
void	run(char *source);

#endif