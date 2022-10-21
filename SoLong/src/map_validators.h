/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validators.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 01:15:16 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/17 00:22:12 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATORS_H
# define MAP_VALIDATORS_H
# include "shared.h"

enum e_map
{
	MAP_BACKGROUND = '0',
	MAP_WALL = '1',
	MAP_COLLECT = 'C',
	MAP_EXIT = 'E',
	MAP_PLAYER = 'P',
};

void	check_map_surrounded_by_walls(t_map *map, char *content, \
	t_resources *resources);
void	find_path_to_exit(t_map *map, t_resources *resources);
void	find_path_to_collectibles(t_map *map, t_resources *resources);

#endif
