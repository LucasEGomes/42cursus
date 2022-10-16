/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:45:45 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 00:46:28 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MOVE_H
# define PLAYER_MOVE_H
# include "shared.h"

int	player_move_up(t_resources *resources);
int	player_move_left(t_resources *resources);
int	player_move_down(t_resources *resources);
int	player_move_right(t_resources *resources);

#endif
