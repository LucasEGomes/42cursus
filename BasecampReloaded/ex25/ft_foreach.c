void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	index;

	if (length < 1)
		return ;
	index = 0;
	while (index < length)
	{
		f(tab[index]);
		index++;
	}
}
