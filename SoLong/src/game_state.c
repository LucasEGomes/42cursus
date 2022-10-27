/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:13:59 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/26 21:44:29 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include "print_utils.h"
#include "free_resources.h"
#include <unistd.h>

void	set_initial_state(t_gui *gui, t_map *map, t_asset *assets)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->grid[y][x].value = map->grid[y][x].original;
			if (map->grid[y][x].value == 'P')
			{
				gui->player_x = x;
				gui->player_y = y;
				gui->movement_count = 0;
				gui->finished = 0;
				map->remaining_collectibles = map->collectibles;
				assets->tick = 0;
				assets->end_cycles = 0;
				assets->end_offset = 0;
			}
		}
	}
}

int	destroy_game(t_resources *resources)
{
	free_resources(resources);
	exit(0);
}

int	restart_game(t_resources *resources)
{
	set_initial_state(resources->gui, resources->map, resources->assets);
	print_message(RESTART_GAME_MESSAGE);
	return (0);
}

int	increase_animation_speed(t_resources *resources)
{
	if (resources->assets->cycle > 40)
		resources->assets->cycle -= 20;
	return (0);
}

int	decrease_animation_speed(t_resources *resources)
{
	if (resources->assets->cycle < 2000)
		resources->assets->cycle += 20;
	return (0);
}
