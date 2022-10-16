/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:40:51 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 17:21:07 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_validators.h"
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
	int		check[0xFF];
	size_t	index;

	index = 0;
	while (index++ < 0xFF)
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
	if (index != 0 && content[index - 1] == '\n')
		check['\n']++;
	map->height = check['\n'];
}

void	configure_map(t_map *map, char *content, t_resources *resources)
{
	(void) map;
	(void) content;
	(void) resources;
}

void	validate_map(t_map *map, t_resources *resources)
{
	(void) map;
	(void) resources;
}

void	load_map(char *filename, t_map *map, t_resources *resources)
{
	char	*content;

	content = read_all_file(filename);
	if (content == NULL)
		raise_exception(EXCEPTION_READ_MAP, resources);
	set_map_size(map, content, resources);
	configure_map(map, content, resources);
	validate_map(map, resources);
}
