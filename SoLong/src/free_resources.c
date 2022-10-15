/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:38:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/15 02:37:02 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_resources.h"

void	free_map(t_map *map)
{
	(void) map;
}

void	free_assets(void *images)
{
	(void) images;
}

void	free_gui(t_gui *gui)
{
	(void) gui;
}

void	free_resources(t_resources *resources)
{
	free_map(resources->map);
	free_assets(resources->assets);
	free_gui(resources->gui);
}
