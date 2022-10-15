/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:40:21 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 23:49:03 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H
# include "shared.h"

void	create_display(t_gui *gui, t_resources *resources);
void	create_window(t_gui *gui, int width, int height, \
	t_resources *resources);

#endif
