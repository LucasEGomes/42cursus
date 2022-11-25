/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:52:53 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/31 20:56:22 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_UTILS_H
# define RENDER_UTILS_H
//                   0xFF000000
//                   0xAA000000
//                   0xAA000000
//                     AARRGGBB
# define TRANSPARENT 0xFF000000
# include "shared.h"

void	*get_frame(void	**array, int frames, int tick, int cycle);
int		*get_data_from_image(void *image);
void	*merge_images(void *background, void *foreground, void *merged, \
	int offset);

#endif
