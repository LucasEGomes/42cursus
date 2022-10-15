/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:41:17 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 23:46:18 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "game.h"
#include "gui.h"
#include "images.h"
#include "map.h"
#include "validators.h"

int	main(int argc, char **argv)
{
	t_resources	resources;
	t_gui		gui;
	t_map		*map;
	void		*images;

	check_arguments(argc, argv);
	create_display(&gui, &resources);
	images = load_images(&gui, &resources);
	map = load_map(argv[1], &resources);
	create_window(&gui, map->width, map->height, &resources);
	game_start(&gui, map, images, &resources);
	return (0);
}
