static int	is_uppercase(int c)
{
	if ((c < 'A') || (c > 'Z'))
		return (0);
	return (1);
}

int	ft_tolower(int c)
{
	if (!is_uppercase(c))
		return (c);
	return (c + 'a' - 'A');
}
