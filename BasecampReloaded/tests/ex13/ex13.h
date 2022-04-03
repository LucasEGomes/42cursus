#ifndef EX13_H
# define EX13_H
# include <unistd.h>
# include <time.h>
# ifndef FACTORIAL_TIMEOUT
#  define FACTORIAL_TIMEOUT 2 * CLOCKS_PER_SEC
# endif

int		ft_recursive_factorial(int nb);
void	run(int number, int expected);

#endif