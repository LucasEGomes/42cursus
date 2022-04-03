void	ft_putchar(char c);

static void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

static int	ft_strcmp(char *s1, char *s2)
{
	int				index;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	index = 0;
	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	while (u_s1[index] != '\0' && u_s2[index] != '\0' && u_s1[index] == u_s2[index])
		index++;
	return ((int)(u_s1[index] - u_s2[index]));
}

static void	ft_swap(char **a, char **b)
{
	char	*aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

static void	ft_strsort(char **strings, int	size)
{
	int	index;
	int	is_sorted;

	is_sorted = 0;
	while (!is_sorted)
	{
		index = 0;
		is_sorted = 1;
		while (index < size - 1)
		{
			if (ft_strcmp(strings[index], strings[index + 1]) > 0)
			{
				ft_swap(&strings[index], &strings[index + 1]);
				is_sorted = 0;
			}
			index++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	index;

	if (argc < 2)
		return (0);
	ft_strsort(&argv[1], argc - 1);
	index = 1;
	while (index < argc)
	{
		ft_putstr(argv[index]);
		ft_putchar('\n');
		index++;
	}
}
