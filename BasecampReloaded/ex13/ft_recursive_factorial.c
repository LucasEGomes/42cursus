int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	if (nb < 2)
		return (1);
	return (ft_recursive_factorial(nb - 1) * nb);
}
