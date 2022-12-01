#include "client.h"
#include "ft_write.h"
#include "ft_atoi.h"
#include <signal.h>

int	invalid_number_of_arguments(void)
{
	ft_write(STDOUT_FILENO, ERROR_INVALID_NUMBER_OF_ARGUMENTS, 93);
	return (1);
}

int	main(int argc, char **argv)
{
	const unsigned char	*string;
	int					signal;
	int					process_id;
	int					index;

	if (argc != 3)
		return (invalid_number_of_arguments());
	process_id = ft_atoi(argv[1]);
	string = (void *) argv[2];
	while (*string != '\0')
	{
		index = 0;
		while (index < 8)
		{
			signal = SIGUSR2;
			if ((*string >> (7 - index)) & 1)
				signal = SIGUSR1;
			usleep(1);
			kill(process_id, signal);
			index++;
		}
		string++;
	}
	index = 0;
	while (index < 8)
	{
		signal = SIGUSR2;
		if ((*string >> (7 - index)) & 1)
			signal = SIGUSR1;
		usleep(1);
		kill(process_id, signal);
		index++;
	}
	return (0);
}
