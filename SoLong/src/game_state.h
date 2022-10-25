/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:14:03 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/22 15:17:33 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STATE_H
# define GAME_STATE_H
# define RESTART_GAME_MESSAGE "Restarting the game...\n"
# include "shared.h"

void	set_initial_state(t_gui *gui, t_map *map, t_asset *assets);
int		destroy_game(t_resources *resources);
int		restart_game(t_resources *resources);
int		increase_animation_speed(t_resources *resources);
int		decrease_animation_speed(t_resources *resources);

#endif
