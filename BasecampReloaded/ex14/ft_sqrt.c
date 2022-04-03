int	ft_sqrt(int nb)
{
	int	divisor;

	divisor = 1;
	while (divisor <= nb / divisor)
	{
		if (divisor * divisor == nb)
			return (divisor);
		divisor++;
	}
	return (0);
}
