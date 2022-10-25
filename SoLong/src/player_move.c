/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:46:30 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/22 16:11:14 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_move.h"
#include "player_move_utils.h"
#include "print_utils.h"
#include "render.h"

static int	player_move(int x, int y, t_resources *resources)
{
	t_map_element	*current;
	t_map_element	*next;

	current = resources->map->grid[resources->gui->player_y] + \
		resources->gui->player_x;
	next = resources->map->grid[resources->gui->player_y + y] + \
		resources->gui->player_x + x;
	if (next->value == RENDER_WALL || resources->gui->finished != 0)
		return (1);
	resources->gui->movement_count++;
	print_number(resources->gui->movement_count);
	if (next->value == RENDER_EXIT)
	{
		if (resources->map->remaining_collectibles == 0)
			return (player_end_game(resources, current, next));
		next->value = RENDER_PLAYER_OVER_EXIT;
	}
	else if (next->value == RENDER_COLLECTIBLE)
		player_get_collectible(resources, next);
	else
		next->value = RENDER_PLAYER_IDLE;
	player_update_render(current);
	resources->gui->player_x += x;
	resources->gui->player_y += y;
	return (0);
}

int	player_move_up(t_resources *resources)
{
	return (player_move(0, -1, resources));
}

int	player_move_left(t_resources *resources)
{
	return (player_move(-1, 0, resources));
}

int	player_move_down(t_resources *resources)
{
	return (player_move(0, 1, resources));
}

int	player_move_right(t_resources *resources)
{
	return (player_move(1, 0, resources));
}
