/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:21:23 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/31 20:45:44 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_move_utils.h"
#include "print_utils.h"
#include "render.h"

int	player_end_game(t_resources *resources, t_map_element *current, \
	t_map_element *next)
{
	next->value = RENDER_PLAYER_GRAB;
	resources->gui->finished = 1;
	current->value = RENDER_BACKGROUND;
	resources->map->grid[next->y][next->x + 1].value = RENDER_END_EXIT;
	print_message(PLAYER_END_GAME_MESSAGE);
	return (1);
}

void	player_get_collectible(t_resources *resources, t_map_element *next)
{
	resources->assets->tick = 0;
	resources->map->remaining_collectibles--;
	next->value = RENDER_EXPLOSION_OVER_PLAYER;
	print_message(PLAYER_GET_COLLECTIBLE_MESSAGE);
}

void	player_update_render(t_map_element *current)
{
	if (current->value == RENDER_PLAYER_OVER_EXIT)
		current->value = RENDER_EXIT;
	else if (current->value == RENDER_EXPLOSION_OVER_PLAYER)
		current->value = RENDER_EXPLOSION;
	else if (current->value == RENDER_EXPLOSION)
		current->value = RENDER_EXPLOSION_OVER_PLAYER;
	else
		current->value = RENDER_BACKGROUND;
}
