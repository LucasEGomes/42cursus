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

int	get_bit(unsigned char value, int index)
{
	const unsigned char	mask = 0b10000000;

	return ((value & (mask >> index)) > 0);
}

void	send_bit(int process_id, unsigned char value, int index)
{
	int	signal;
	int	encode_index;
	const unsigned char	mask = 0b10000000;

	signal = SIGUSR2;
	if (get_bit(value, index))
		signal = SIGUSR1;
	encode_index = 0;
	while (encode_index < 5)
	{
		kill(process_id, signal);
		while(usleep(1000) == 0)
			;
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

void	setup_acknowledge(void)
{
	const int	signals[] = {SIGUSR1, SIGUSR2, 0};
	setup_action(&listener, signals, 0);
}

int	main(int argc, char **argv)
{
	unsigned char		*message;
	int					process_id;

	if (argc != 3)
		return (invalid_number_of_arguments());
	setup_acknowledge();
	process_id = ft_atoi(argv[1]);
	message = (void *) argv[2];
	while (*message != '\0')
		send_byte(process_id, *message++);
	send_byte(process_id, '\0');
	return (0);
}
