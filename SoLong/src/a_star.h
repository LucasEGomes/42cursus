/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:18:50 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/26 23:57:11 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_STAR_H
# define A_STAR_H
# include "shared.h"

t_map_element	*a_star_search(t_map_element *start, t_map_element *end, \
	t_map *map, t_resources *resources);

#endif
