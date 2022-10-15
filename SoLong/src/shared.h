/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:49:11 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 23:49:11 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

typedef struct s_map
{
	int		width;
	int		height;
	char	*values;
}	t_map;

typedef struct s_gui
{
	void	*display;
	void	*window;
}	t_gui;

typedef struct s_resources
{
	t_map	*map;
	t_gui	*gui;
	void	*images;
}	t_resources;

#endif
