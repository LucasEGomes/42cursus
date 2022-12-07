#include "client.h"
#include "ft_strlen.h"
#include "ft_write.h"
#include "ft_atoi.h"
#include <signal.h>

int	invalid_number_of_arguments(void)
{
	ft_write(STDOUT_FILENO, ERROR_INVALID_NUMBER_OF_ARGUMENTS, 93);
	return (1);
}

int	encode(int	signal, int index)
{
	if (signal == SIGUSR1)
	{
		if (index == 0 || index == 4)
			return (SIGUSR1);
		return (SIGUSR2);
	}
	if (index == 0 || index == 4)
		return (SIGUSR2);
	return (SIGUSR1);
}

void	send_bit(int process_id, unsigned char value, int index)
{
	int	signal;
	int	encode_index;

	signal = SIGUSR2;
	if ((value >> (7 - index)) & 1)
		signal = SIGUSR1;
	encode_index = 0;
	while (encode_index < 5)
	{
		usleep(1);
		kill(process_id, encode(signal, encode_index));
		encode_index++;
	}
}

void	send_byte(int process_id, unsigned char value)
{
	int	index;
	
	index = 0;
	while (index < 8)
		send_bit(process_id, value, index++);
}

int	main(int argc, char **argv)
{
	unsigned char		*message;
	int					process_id;

	if (argc != 3)
		return (invalid_number_of_arguments());
	process_id = ft_atoi(argv[1]);
	message = (void *) argv[2];
	while (*message != '\0')
		send_byte(process_id, *message++);
	send_byte(process_id, '\0');
	return (0);
}
