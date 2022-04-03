#ifndef EX14_H
# define EX14_H
# include <unistd.h>
# include <time.h>
# ifndef TIMEOUT
#  define TIMEOUT 2 * CLOCKS_PER_SEC
# endif

int		ft_sqrt(int nb);
void	run(int number, int expected);

#endif
