#include "ft_display_file.h"

static int	too_many_arguments_error(void)
{
	ft_putstr("Too many arguments.\n");
	return (0);
}

static int	file_is_missing_error(void)
{
	ft_putstr("File name missing.\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int file_descriptor;

	if (argc < 2)
		return (file_is_missing_error());
	if (argc > 2)
		return (too_many_arguments_error());
	file_descriptor = open(argv[1], O_RDONLY);
	read_file(file_descriptor);
	close(file_descriptor);
	write(1, "\n", 1);
	return (0);
}
