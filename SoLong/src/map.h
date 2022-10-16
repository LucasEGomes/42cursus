/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:40:52 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 17:15:04 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "shared.h"

enum e_map
{
	MAP_BACKGROUND = '0',
	MAP_WALL = '1',
	MAP_COLLECT = 'C',
	MAP_EXIT = 'E',
	MAP_PLAYER = 'P',
};

void	load_map(char *filename, t_map *map, t_resources *resources);

#endif
