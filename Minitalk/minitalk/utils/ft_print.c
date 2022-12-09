#include "utils/ft_absolute.h"
#include "utils/ft_count_digits.h"
#include "utils/ft_strlen.h"
#include "utils/ft_write.h"

void	ft_print_str(int file_descriptor, void *string)
{
	ft_write(file_descriptor, string, ft_strlen(string));
}

void	ft_print_int(int file_descriptor, int number)
{
	char	string[12];
	int		digits;
	int		is_negative;

	digits = ft_count_digits_int(number, 10);
	is_negative = number < 0;
	if (is_negative)
	{
		digits++;
		string[0] = '-';
	}
	string[digits] = '\0';
	while (digits > is_negative)
	{
		digits--;
		string[digits] = "0123456789"[ft_absolute_int(number % 10)];
		number = number / 10;
	}
	ft_print_str(file_descriptor, string);
}
