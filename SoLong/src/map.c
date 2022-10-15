/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:40:51 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 23:48:50 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>

t_map	*load_map(char *filename, t_resources *resources)
{
	t_map	*map;

	(void) filename;
	(void) resources;
	map = malloc(sizeof(*map));
	map->width = 400;
	map->height = 200;
	map->values = NULL;
	return (map);
}
