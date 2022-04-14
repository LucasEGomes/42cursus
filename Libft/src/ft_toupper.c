static int	is_lowercase(int c)
{
	if ((c < 'a') || (c > 'z'))
		return (0);
	return (1);
}

int	ft_toupper(int c)
{
	if (!is_lowercase(c))
		return (c);
	return (c - 'a' + 'A');
}
