/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_animations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:56:41 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/22 15:58:05 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_ANIMATIONS_H
# define RENDER_ANIMATIONS_H
# include "shared.h"

void	*put_explosion(t_asset *assets, t_map_element *element, t_map *map);
void	*put_exit(t_asset *assets, t_map_element *element, t_map *map);
void	*put_player(t_asset *assets, t_map_element *element, t_map *map);
void	*put_end_game(t_asset *assets, t_map_element *element, t_map *map);

#endif
