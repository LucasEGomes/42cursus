/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:38:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/26 21:35:22 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_resources.h"
#include "mlx.h"
#include <stdlib.h>

void	free_map(t_map *map)
{
	int	row;

	if (map == NULL || map->grid == NULL)
		return ;
	row = -1;
	while (++row < map->height)
	{
		if (map->grid[row] != NULL)
			free(map->grid[row]);
	}
	free(map->grid);
}

void	free_asset_array(void *display, void **array, int frames)
{
	int	frame;

	frame = -1;
	while (++frame < frames)
	{
		if (array[frame] != NULL)
			mlx_destroy_image(display, array[frame]);
	}
}

void	free_assets(void *display, t_asset *assets)
{
	free_asset_array(display, assets->background, BACKGROUND_FRAMES);
	free_asset_array(display, assets->ceiling, CEILING_FRAMES);
	free_asset_array(display, assets->collectible, COLLECTIBLE_FRAMES);
	free_asset_array(display, assets->exit, EXIT_FRAMES);
	free_asset_array(display, assets->explosion, EXPLOSION_FRAMES);
	free_asset_array(display, assets->floor, FLOOR_FRAMES);
	free_asset_array(display, assets->platform, PLATFORM_FRAMES);
	free_asset_array(display, assets->player_grab, PLAYER_GRAB_FRAMES);
	free_asset_array(display, assets->player_walk, PLAYER_WALK_FRAMES);
	free_asset_array(display, assets->wall, WALL_FRAMES);
	free_asset_array(display, &(assets->temp), 1);
}

void	free_gui(t_gui *gui)
{
	if (gui->display == NULL)
		return ;
	if (gui->window != NULL)
		mlx_destroy_window(gui->display, gui->window);
	mlx_destroy_display(gui->display);
	free(gui->display);
}

void	free_resources(t_resources *resources)
{
	free_map(resources->map);
	free_assets(resources->gui->display, resources->assets);
	free_gui(resources->gui);
}
