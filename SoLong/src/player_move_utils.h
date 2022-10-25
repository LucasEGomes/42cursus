/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:21:13 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/22 16:11:09 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MOVE_UTILS_H
# define PLAYER_MOVE_UTILS_H
# define PLAYER_GET_COLLECTIBLE_MESSAGE "So long, Bowser!\n"
# define PLAYER_END_GAME_MESSAGE "Thank you Mario!\
\nBut our princess is in another castle!\
\nPress 'Esc' to quit or 'R' to restart the game...\n"
# include "shared.h"

int		player_end_game(t_resources *resources, t_map_element *current, \
	t_map_element *next);
void	player_get_collectible(t_resources *resources, t_map_element *next);
void	player_update_render(t_map_element *current);

#endif
