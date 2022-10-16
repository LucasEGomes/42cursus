/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:39:26 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/15 18:44:10 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "mlx.h"
#include "exceptions.h"
#include <stdlib.h>

void	create_display(t_gui *gui, t_resources *resources)
{
	gui->display = mlx_init();
	if (gui->display == NULL)
		raise_exception("Failed to create display.\n", resources);
}

void	create_window(t_gui *gui, int width, int height, t_resources *resources)
{
	gui->window = mlx_new_window(gui->display, width, height, \
		"So long, Bowser!");
	if (gui->window == NULL)
		raise_exception("Failed to create window.\n", resources);
}
