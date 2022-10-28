/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:56:55 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/27 00:33:05 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_animations.h"
#include "render.h"
#include "render_utils.h"

void	*put_explosion(t_asset *assets, t_map_element *element, t_map *map)
{
	void	*frame;
	void	*player;

	(void) map;
	frame = get_frame(assets->explosion, 10, assets->tick, assets->cycle);
	if (frame >= assets->explosion[8])
	{
		if (element->value == RENDER_EXPLOSION_OVER_PLAYER)
			element->value = RENDER_PLAYER_IDLE;
		else
			element->value = RENDER_BACKGROUND;
	}
	if (element->value == RENDER_EXPLOSION)
		return (merge_images(assets->background[0], frame, assets->temp[0], 0));
	player = get_frame(assets->player_walk, 4, assets->tick, assets->cycle);
	frame = merge_images(player, frame, assets->temp[0], 0);
	return (merge_images(assets->background[0], frame, assets->temp[0], 0));
}

void	*put_exit(t_asset *assets, t_map_element *element, t_map *map)
{
	void	*frame;
	void	*player;

	(void) map;
	if (element->value == RENDER_PLAYER_GRAB)
	{
		player = assets->player_grab[0];
		frame = merge_images(assets->exit[1], player, assets->temp[1], 0);
		element->value = RENDER_END_GAME;
	}
	else if (element->value == RENDER_PLAYER_OVER_EXIT)
	{
		player = get_frame(assets->player_walk, 4, assets->tick, assets->cycle);
		frame = merge_images(assets->exit[0], player, assets->temp[1], 0);
	}
	else if (element->value == RENDER_END_EXIT)
		frame = assets->exit[2];
	else
		frame = assets->exit[0];
	return (merge_images(assets->background[0], frame, assets->temp[1], 0));
}

void	*put_player(t_asset *assets, t_map_element *element, t_map *map)
{
	void	*frame;

	(void) element;
	(void) map;
	frame = get_frame(assets->player_walk, 4, assets->tick, assets->cycle);
	return (merge_images(assets->background[0], frame, assets->temp[2], 0));
}

void	*put_end_game(t_asset *assets, t_map_element *element, t_map *map)
{
	void		*player;
	void		*frame;

	(void) element;
	(void) map;
	if (assets->end_offset > GRID - 1)
		return (merge_images(assets->background[0], assets->exit[1], \
			assets->temp[3], 0));
	if (assets->end_cycles < 2)
		player = assets->player_grab[0];
	else
		player = get_frame(assets->player_walk, 4, assets->tick, assets->cycle);
	frame = merge_images(assets->exit[1], player, assets->temp[3], \
		assets->end_offset);
	if (assets->end_cycles < 2 && assets->tick == 0)
		assets->end_cycles++;
	if (player != assets->player_grab[0] && assets->tick % 100 == 0)
		assets->end_offset++;
	return (merge_images(assets->background[0], frame, assets->temp[3], 0));
}
