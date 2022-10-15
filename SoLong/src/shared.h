/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:49:11 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/15 18:37:35 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# define SUCCESS		0
# define FAILURE		1
# define GRID				20
# define BACKGROUND_FOLDER	"assets/xpm/background"
# define BACKGROUND_FRAMES	1
# define COLLECTIBLE_FOLDER	"assets/xpm/collectible"
# define COLLECTIBLE_FRAMES	1
# define EXIT_FOLDER		"assets/xpm/exit"
# define EXIT_FRAMES		2
# define EXPLOSION_FOLDER	"assets/xpm/explosion"
# define EXPLOSION_FRAMES	10
# define PLAYER_GRAB_FOLDER	"assets/xpm/player/grab"
# define PLAYER_GRAB_FRAMES	1
# define PLAYER_WALK_FOLDER	"assets/xpm/player/walk"
# define PLAYER_WALK_FRAMES	4
# define CEILING_FOLDER		"assets/xpm/ceiling"
# define CEILING_FRAMES		1
# define FLOOR_FOLDER		"assets/xpm/floor"
# define FLOOR_FRAMES		1
# define PLATFORM_FOLDER	"assets/xpm/platform"
# define PLATFORM_FRAMES	1
# define WALL_FOLDER		"assets/xpm/wall"
# define WALL_FRAMES		1

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

typedef struct s_asset
{
	void	*background[BACKGROUND_FRAMES];
	void	*collectible[COLLECTIBLE_FRAMES];
	void	*exit[EXIT_FRAMES];
	void	*explosion[EXPLOSION_FRAMES];
	void	*player_grab[PLAYER_GRAB_FRAMES];
	void	*player_walk[PLAYER_WALK_FRAMES];
	void	*ceiling[CEILING_FRAMES];
	void	*floor[FLOOR_FRAMES];
	void	*platform[PLATFORM_FRAMES];
	void	*wall[WALL_FRAMES];
}	t_asset;

typedef struct s_resources
{
	t_gui	*gui;
	t_asset	*assets;
	t_map	*map;
}	t_resources;

#endif
