/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 01:15:14 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/20 21:07:48 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validators.h"
#include "a_star.h"
#include "exceptions.h"
#include <stdlib.h>

void	check_map_surrounded_by_walls(t_map *map, char *content, \
	t_resources *resources)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((x == 0 || y == 0 || \
				x == map->width - 1 || y == map->height - 1) && \
				content[y * (map->width + 1) + x] != MAP_WALL)
				raise_file_exception(EXCEPTION_SURROUNDED_BY_WALLS, content, \
					resources);
			x++;
		}
		y++;
	}
}

void	*find_element_from(t_map *map, char value, int *x, int *y)
{
	int	temp_x;
	int	temp_y;

	temp_x = 0;
	temp_y = 0;
	if (x == NULL)
		x = &temp_x;
	if (y == NULL)
		y = &temp_y;
	while (*y < map->height)
	{
		while (*x < map->width)
		{
			if (map->grid[*y][*x].value == value)
				return (&map->grid[*y][*x]);
			(*x)++;
		}
		(*y)++;
		*x = 0;
	}
	return (NULL);
}

void	find_path_to_exit(t_map *map, t_resources *resources)
{
	void	*start;
	void	*end;

	start = find_element_from(map, MAP_PLAYER, NULL, NULL);
	end = find_element_from(map, MAP_EXIT, NULL, NULL);
	if (a_star_search(start, end, map, resources) == NULL)
		raise_exception(EXCEPTION_EXIT_PATH, resources);
}

void	find_path_to_collectibles(t_map *map, t_resources *resources)
{
	int		x;
	int		y;
	void	*start;
	void	*end;

	start = find_element_from(map, MAP_PLAYER, NULL, NULL);
	x = 0;
	y = 0;
	end = find_element_from(map, MAP_COLLECT, &x, &y);
	while (end != NULL)
	{
		if (a_star_search(start, end, map, resources) == NULL)
			raise_exception(EXCEPTION_COLLECTIBLE_PATH, resources);
		x++;
		end = find_element_from(map, MAP_COLLECT, &x, &y);
	}
}
