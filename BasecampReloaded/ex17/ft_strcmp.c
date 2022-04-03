int	ft_strcmp(char *s1, char *s2)
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
