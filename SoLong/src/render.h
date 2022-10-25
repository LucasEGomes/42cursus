/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:52:16 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/22 15:54:00 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# define ANIMATION_RESET 19
# include "shared.h"

enum	e_render_elements
{
	RENDER_BACKGROUND = '0',
	RENDER_WALL = '1',
	RENDER_COLLECTIBLE = 'C',
	RENDER_EXIT = 'E',
	RENDER_PLAYER_GRAB = 'F',
	RENDER_PLAYER_OVER_EXIT = 'G',
	RENDER_END_GAME = 'H',
	RENDER_END_EXIT = 'I',
	RENDER_PLAYER_IDLE = 'P',
	RENDER_EXPLOSION_OVER_PLAYER = 'Q',
	RENDER_EXPLOSION = 'R'
};
typedef void *	(*t_frame_delegator)(t_asset *assets, t_map_element *element, \
	t_map *map);
void	render_game(t_resources *resources);

#endif
