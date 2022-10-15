/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:41:17 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 22:47:50 by luceduar         ###   ########.fr       */
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
	t_gui	*gui;
	t_map	*map;
	void	*images;

	check_arguments(argc, argv);
	gui = load_gui();
	images = load_images(gui);
	map = load_map(argv[1]);
	create_window(gui, map->width, map->height);
	game_start(gui, map, images);
	return (0);
}
