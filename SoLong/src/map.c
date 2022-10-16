/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:40:51 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 01:04:27 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "file_utils.h"
#include "exceptions.h"
#include <stdlib.h>

void	check_map_content(char *content, t_resources *resources)
{
	(void) content;
	(void) resources;
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
		raise_exception("Failed to read map file.\n", resources);
	check_map_content(content, resources);
	configure_map(map, content, resources);
	validate_map(map, resources);
}
