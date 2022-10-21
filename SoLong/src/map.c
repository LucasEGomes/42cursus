/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:40:51 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/20 21:22:57 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_validators.h"
#include "a_star.h"
#include "file_utils.h"
#include "exceptions.h"
#include <stdlib.h>

int	is_valid_content(char value)
{
	return (value == MAP_BACKGROUND || \
		value == MAP_COLLECT || \
		value == MAP_EXIT || \
		value == MAP_PLAYER || \
		value == MAP_WALL || \
		value == '\n');
}

void	set_map_size(t_map *map, char *content, t_resources *resources)
{
	int		check[MAP_VALUE_LIMIT];
	size_t	index;

	index = 0;
	while (index++ < MAP_VALUE_LIMIT - 1)
		check[index] = 0;
	index = 0;
	while (content[index] != '\0')
	{
		if (!is_valid_content(content[index]))
			raise_file_exception(EXCEPTION_INVALID_VALUE, content, resources);
		if (content[index] == '\n' && map->width != 0 && \
			content[index - map->width - 1] != '\n')
			raise_file_exception(EXCEPTION_RECTANGULAR, content, resources);
		if (map->width == 0 && content[index] == '\n')
			map->width = (int)index;
		check[(size_t)content[index]]++;
		index++;
	}
	if (!check[MAP_COLLECT] || check[MAP_EXIT] != 1 || check[MAP_PLAYER] != 1)
		raise_file_exception(EXCEPTION_MINIMAL_ELEMENTS, content, resources);
	if (index != 0 && content[index - 1] != '\n')
		check['\n']++;
	map->height = check['\n'];
}

void	configure_map(t_map *map, char *content, t_resources *resources)
{
	int	x;
	int	y;

	map->grid = malloc(map->height * sizeof(*(map->grid)));
	if (map->grid == NULL)
		raise_file_exception(EXCEPTION_MAP, content, resources);
	y = -1;
	while (++y < map->height)
	{
		map->grid[y] = malloc(map->width * sizeof(*(map->grid[y])));
		if (map->grid[y] == NULL)
		{
			while (y >= 0)
				free(map->grid[y--]);
			raise_file_exception(EXCEPTION_MAP, content, resources);
		}
		x = -1;
		while (++x < map->width)
		{
			map->grid[y][x].value = content[y * (map->width + 1) + x];
			map->grid[y][x].x = x;
			map->grid[y][x].y = y;
			map->grid[y][x].visited = 0;
		}
	}
}

void	validate_map(t_map *map, t_resources *resources)
{
	int	x;
	int	y;

	find_path_to_exit(map, resources);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->grid[y][x].visited = 0;
			x++;
		}
		y++;
	}
	find_path_to_collectibles(map, resources);
}

void	load_map(char *filename, t_map *map, t_resources *resources)
{
	char	*content;

	content = read_all_file(filename);
	if (content == NULL)
		raise_exception(EXCEPTION_READ_MAP, resources);
	set_map_size(map, content, resources);
	check_map_surrounded_by_walls(map, content, resources);
	configure_map(map, content, resources);
	free(content);
	validate_map(map, resources);
}
