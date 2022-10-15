#ifndef SHARED_H
# define SHARED_H

typedef struct s_map
{
	int		width;
	int		height;
	char	value;
}	t_map;

typedef struct s_gui
{
	void	*display;
	void	*window;
}	t_gui;

#endif
