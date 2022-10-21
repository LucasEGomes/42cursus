/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:40:52 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 20:38:05 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# define MAP_VALUE_LIMIT 0x100
# include "shared.h"

void	load_map(char *filename, t_map *map, t_resources *resources);

#endif
