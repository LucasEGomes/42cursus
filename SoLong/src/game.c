/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:46:08 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/22 15:59:01 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "game_state.h"
#include "player_move.h"
#include "render.h"
#include "mlx.h"
#include "mlx_int.h"

int	loop_handler(t_resources *resources)
{
	render_game(resources);
	return (0);
}

int	key_handler(int keycode, void *param)
{
	static t_key_event	delegator[0xFFFF];

	if (delegator[XK_Up] == NULL)
	{
		delegator[XK_Up] = player_move_up;
		delegator[XK_W] = player_move_up;
		delegator[XK_w] = player_move_up;
		delegator[XK_Left] = player_move_left;
		delegator[XK_A] = player_move_left;
		delegator[XK_a] = player_move_left;
		delegator[XK_Down] = player_move_down;
		delegator[XK_S] = player_move_down;
		delegator[XK_s] = player_move_down;
		delegator[XK_Right] = player_move_right;
		delegator[XK_D] = player_move_right;
		delegator[XK_d] = player_move_right;
		delegator[XK_Escape] = destroy_game;
		delegator[XK_R] = restart_game;
		delegator[XK_r] = restart_game;
		delegator[XK_Page_Up] = increase_animation_speed;
		delegator[XK_Page_Down] = decrease_animation_speed;
	}
	if (keycode >= 0xFFFF || delegator[keycode] == NULL)
		return (0);
	return (delegator[keycode](param));
}

void	game_start(t_gui *gui, t_resources *resources)
{
	resources->assets->temp = mlx_new_image(resources->gui->display, \
		GRID, GRID);
	set_initial_state(resources->gui, resources->map, resources->assets);
	mlx_hook(gui->window, DestroyNotify, 0, &destroy_game, resources);
	mlx_loop_hook(gui->display, &loop_handler, resources);
	mlx_key_hook(gui->window, &key_handler, resources);
	mlx_loop(gui->display);
}
