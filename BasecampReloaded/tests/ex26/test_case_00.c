#include <unistd.h>

int	ft_count_if(char **tab, int (*f)(char *));

int	ft_len_gt_5(char *s)
{
	int	index;
	
	index = 0;
	while (s[index] != '\0')
		index++;
	if (index <= 5)
		return (0);
	return (1);
}

void	run(char **words, int (*f)(char *), int expected)
{
	int	result;

	result = ft_count_if(words, f);
	if (expected == result)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(void)
{
	char	*words_0[] = {"Hello", "There", "General", "Kenobi", 0};
	char	*words_1[] = {"There", "General", "Ken", "obi", 0};
	
	run(words_0, ft_len_gt_5, 2);
	run(words_1, ft_len_gt_5, 1);
}