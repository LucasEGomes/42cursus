#include "client.h"
#include "ft_write.h"

int	invalid_number_of_arguments(void)
{
	ft_write(STDOUT_FILENO, INVALID_NUMBER_OF_ARGUMENTS, 94);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (invalid_number_of_arguments());
	return (0);
}
