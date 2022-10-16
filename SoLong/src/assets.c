/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:45:01 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 13:42:00 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "exceptions.h"
#include "string_utils.h"
#include "mlx.h"
#include <stdlib.h>

char	*get_frame_file(char *path, int frame)
{
	char	number[2];
	char	*filename;
	char	*result;

	number[0] = (char)(frame) + '0';
	number[1] = '\0';
	filename = string_join(FRAME_PREFIX, number);
	if (filename == NULL)
		return (NULL);
	filename = string_join(filename, IMAGE_SUFFIX);
	if (filename == NULL)
	{
		free(filename);
		return (NULL);
	}
	result = string_join(path, filename);
	free(filename);
	return (result);
}

void	*load_image(void *display, char *file)
{
	int	_;

	return (mlx_xpm_file_to_image(display, file, &_, &_));
}

int	load_frames(void *display, void *array[], char *path, int frames)
{
	int		frame;
	char	*file;
	void	*image;

	frame = 0;
	while (frame < frames)
	{
		file = get_frame_file(path, frame);
		if (file == NULL)
			return (FAILURE);
		image = load_image(display, file);
		free(file);
		if (image == NULL)
			return (FAILURE);
		array[frame] = image;
		frame++;
	}
	return (SUCCESS);
}

void	load_assets(t_gui *gui, t_asset *assets, t_resources *resources)
{
	int	has_failed;

	has_failed = 0;
	has_failed += load_frames(gui->display, assets->background, \
		BACKGROUND_FOLDER, BACKGROUND_FRAMES);
	has_failed += load_frames(gui->display, assets->collectible, \
		COLLECTIBLE_FOLDER, COLLECTIBLE_FRAMES);
	has_failed += load_frames(gui->display, assets->exit, \
		EXIT_FOLDER, EXIT_FRAMES);
	has_failed += load_frames(gui->display, assets->explosion, \
		EXPLOSION_FOLDER, EXPLOSION_FRAMES);
	has_failed += load_frames(gui->display, assets->player_grab, \
		PLAYER_GRAB_FOLDER, PLAYER_GRAB_FRAMES);
	has_failed += load_frames(gui->display, assets->player_walk, \
		PLAYER_WALK_FOLDER, PLAYER_WALK_FRAMES);
	has_failed += load_frames(gui->display, assets->ceiling, \
		CEILING_FOLDER, CEILING_FRAMES);
	has_failed += load_frames(gui->display, assets->floor, \
		FLOOR_FOLDER, FLOOR_FRAMES);
	has_failed += load_frames(gui->display, assets->platform, \
		PLATFORM_FOLDER, PLATFORM_FRAMES);
	has_failed += load_frames(gui->display, assets->wall, \
		WALL_FOLDER, WALL_FRAMES);
	if (has_failed > 0)
		raise_exception(EXCEPTION_LOAD_ASSETS, resources);
}
