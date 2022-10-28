/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:51:54 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/27 00:32:42 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "render_utils.h"
#include "render_animations.h"
#include "map_validators.h"
#include "mlx.h"
#include <stdlib.h>

void	*put_background(t_asset *assets, t_map_element *element, t_map *map)
{
	(void) element;
	(void) map;
	return (assets->background[0]);
}

void	*put_collectible(t_asset *assets, t_map_element *element, t_map *map)
{
	void	*frame;

	(void) element;
	(void) map;
	frame = assets->collectible[0];
	return (merge_images(assets->background[0], frame, assets->temp[4], 0));
}

void	*put_wall(t_asset *assets, t_map_element *element, t_map *map)
{
	if (element->y == 0)
		return (assets->ceiling[0]);
	else if (element->y == map->height - 1)
		return (assets->floor[0]);
	else if (element->x == 0 || element->x == map->width - 1)
		return (assets->wall[0]);
	else
		return (assets->platform[0]);
}

void	render(t_resources *resources, t_map_element *current)
{
	static t_frame_delegator	delegator[0xFF];
	void						*current_frame;

	if (delegator[RENDER_BACKGROUND] == NULL)
	{
		delegator[RENDER_BACKGROUND] = &put_background;
		delegator[RENDER_WALL] = &put_wall;
		delegator[RENDER_COLLECTIBLE] = &put_collectible;
		delegator[RENDER_EXIT] = &put_exit;
		delegator[RENDER_PLAYER_GRAB] = &put_exit;
		delegator[RENDER_PLAYER_OVER_EXIT] = &put_exit;
		delegator[RENDER_END_GAME] = &put_end_game;
		delegator[RENDER_END_EXIT] = &put_exit;
		delegator[RENDER_PLAYER_IDLE] = &put_player;
		delegator[RENDER_EXPLOSION_OVER_PLAYER] = &put_explosion;
		delegator[RENDER_EXPLOSION] = &put_explosion;
	}
	if (delegator[(int) current->value] == NULL)
		current_frame = put_background(resources->assets, current, \
			resources->map);
	else
		current_frame = delegator[(int) current->value](resources->assets, \
			current, resources->map);
	mlx_put_image_to_window(resources->gui->display, resources->gui->window, \
		current_frame, current->x * GRID, current->y * GRID);
}

void	render_game(t_resources *resources)
{
	int	x;
	int	y;

	resources->assets->tick++;
	resources->assets->tick %= resources->assets->cycle;
	if (resources->assets->tick % 20 != 0)
		return ;
	y = 0;
	while (y < resources->map->height)
	{
		x = 0;
		while (x < resources->map->width)
		{
			render(resources, &(resources->map->grid[y][x]));
			x++;
		}
		y++;
	}
}
