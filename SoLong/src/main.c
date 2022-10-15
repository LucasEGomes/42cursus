/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:41:17 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/15 18:34:50 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "game.h"
#include "gui.h"
#include "assets.h"
#include "map.h"
#include "validators.h"

void	initialize_resources(t_gui *gui, t_asset *assets, t_map	*map, \
	t_resources *resources)
{
	resources->gui = gui;
	resources->assets = assets;
	resources->map = map;
}

int	main(int argc, char **argv)
{
	static t_gui	gui;
	static t_asset	assets;
	static t_map	map;
	t_resources		resources;

	check_arguments(argc, argv);
	initialize_resources(&gui, &assets, &map, &resources);
	create_display(&gui, &resources);
	load_assets(&gui, &assets, &resources);
	load_map(argv[1], &map, &resources);
	create_window(&gui, map.width, map.height, &resources);
	game_start(&gui, &map, &assets, &resources);
	return (0);
}
