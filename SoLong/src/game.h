/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:45:07 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 01:04:40 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "shared.h"

typedef int	(*t_key_event)(t_resources *resources);
void	game_start(t_gui *gui, t_resources *resources);

#endif
