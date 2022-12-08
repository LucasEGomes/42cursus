int	ft_count_digits_int(int number, int base_size)
{
	int	digits;
	int	limit;

	if (base_size < 2)
		return (-1);
	digits = 1;
	limit = base_size - 1;
	while ((number < -limit) | (number > limit))
	{
		number /= base_size;
		digits++;
	}
	return (digits);
}
