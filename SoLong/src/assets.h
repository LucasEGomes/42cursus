/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:45:03 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/27 20:59:31 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H
# define FRAME_PREFIX "/frame_"
# define IMAGE_SUFFIX ".xpm"
# include "shared.h"

void	load_assets(t_gui *gui, t_asset *assets, t_resources *resources);
void	allocate_animation_assets(t_gui *gui, t_asset *assets, t_resources \
	*resources);

#endif
