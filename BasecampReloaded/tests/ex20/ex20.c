#include "ex20.h"

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

void	run(char *source)
{
	char	*result;

	result = ft_strdup(source);
	if (result == NULL)
	{
		write(1, "Malloc failed\n", 14);
		return ;
	}
	if (ft_strcmp(source, result) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(result);
}
