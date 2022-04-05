#ifndef EX21_H
# define EX21_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

extern void	*__real_malloc(size_t size);
int			*ft_range(int min, int max);
void		run(int min, int max, int *expected);

#endif