int	ft_count_if(char **tab, int (*f)(char *))
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (tab[index] != ((void *) 0))
	{
		if (f(tab[index]) == 1)
			count++;
		index++;
	}
	return (count);
}
