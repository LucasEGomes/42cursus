/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:53:09 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/31 21:07:12 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_utils.h"
#include "mlx.h"

void	*get_frame(void	**array, int frames, int tick, int cycle)
{
	int	frame;

	// chamadas de função - tick
	// máximo de chamadas - cycle
	// frames - 4
	// 500 * 4 / 2000 == 0
	// 501 * 4 == 2004 / 2000 == 1
	// 20
	// 20
	// 0 - 10 == 0
	// 11 - 15 == 1
	// 16 -17 == 2
	// 18 - 19 == 3
	frame = tick * frames / cycle;
	if (frame >= frames)
		frame = frames - 1;
	if (frame < 0)
		frame = 0;
	return (array[frame]);
}

int	*get_data_from_image(void *image)
{
	int	_;

	return ((void *) mlx_get_data_addr(image, &_, &_, &_));
}

void	*merge_images(void *background, void *foreground, void *merged, \
	int offset)
{
	int	*background_data;
	int	*foreground_data;
	int	*merged_data;
	int	x;
	int	y;

	background_data = get_data_from_image(background);
	foreground_data = get_data_from_image(foreground);
	merged_data = get_data_from_image(merged);
	y = 0;
	while (y < GRID * GRID)
	{
		x = 0;
		while (x < GRID)
		{
			if (x >= offset && \
				(foreground_data[y + x - offset] & TRANSPARENT) == 0)
				merged_data[y + x] = foreground_data[y + x - offset];
			else
				merged_data[y + x] = background_data[y + x];
			x++;
		}
		y += GRID;
	}
	return (merged);
}
