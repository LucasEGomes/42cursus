#ifndef EX12_H
# define EX12_H
# include <unistd.h>
# include <time.h>
# ifndef FACTORIAL_TIMEOUT
#  define FACTORIAL_TIMEOUT 2 * CLOCKS_PER_SEC
# endif

int		ft_iterative_factorial(int nb);
void	run(int number, int expected);

#endif