#ifndef EX11_H
# define EX11_H
# include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod);
void	run(int numerator,
	int denominator,
	int expected_quotient,
	int expected_remainder);

#endif