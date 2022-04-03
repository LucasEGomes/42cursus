#include "ex11.h"

void	run(int numerator,
	int denominator,
	int expected_quotient,
	int expected_remainder)
{
	int	quotient;
	int	remainder;

	ft_div_mod(numerator, denominator, &quotient, &remainder);
	if(expected_quotient == quotient && expected_remainder == remainder)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
