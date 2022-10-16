/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:46:30 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 01:06:41 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_move.h"

static int	player_move(int x, int y, t_resources *resources)
{
	(void) x;
	(void) y;
	(void) resources;
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
