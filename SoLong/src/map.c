/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:40:51 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/15 02:46:14 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>

t_map	*load_map(char *filename, t_map *map, t_resources *resources)
{
	(void) filename;
	(void) resources;
	map = malloc(sizeof(*map));
	map->width = 400;
	map->height = 200;
	map->values = NULL;
	return (map);
}
