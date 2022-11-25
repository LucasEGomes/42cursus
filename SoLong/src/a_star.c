/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:19:44 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/31 20:16:37 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_star.h"
#include "double_list.h"
#include "map_validators.h"
#include "exceptions.h"
#include <stdlib.h>

long	heuristic(long start_x, long start_y, long end_x, long end_y)
{
	long	delta_x;
	long	delta_y;
	long	squared_distance;
	long	squared_manhattan;

	delta_x = start_x - end_x;
	if (delta_x < 0)
		delta_x = -delta_x;
	delta_y = start_y - end_y;
	if (delta_y < 0)
		delta_y = -delta_y;
	squared_distance = delta_x * delta_x + delta_y * delta_y;
	squared_manhattan = delta_x + delta_y;
	squared_manhattan *= squared_manhattan;
	(void) squared_manhattan;
	return (squared_distance);
}

int	compare_elements(void *left, void *right)
{
	t_map_element	*cast_left;
	t_map_element	*cast_right;

	cast_left = left;
	cast_right = right;
	if (cast_left == cast_right)
		return (0);
	if (cast_right == NULL)
		return (0);
	if (cast_left == NULL)
		return (1);
	if (cast_right->evaluation < cast_left->evaluation)
		return (1);
	return (0);
}

int	evaluate_node(t_double_list **head, \
	t_map_element *start, t_map_element *end)
{
	t_double_list	*node;

	if (start->original == MAP_WALL || start->visited != 0)
		return (SUCCESS);
	start->evaluation = heuristic(start->x, start->y, end->x, end->y);
	start->visited = 1;
	node = double_list_new_node(start);
	if (node == NULL)
		return (FAILURE);
	double_list_add_back(head, node);
	return (SUCCESS);
}

int	evaluate_around_nodes(t_double_list **head, t_map *map, \
	t_map_element *start, t_map_element *end)
{
	t_map_element	*element;

	element = &(map->grid[start->y][start->x + 1]);
	if (evaluate_node(head, element, end))
		return (FAILURE);
	element = &(map->grid[start->y - 1][start->x]);
	if (evaluate_node(head, element, end))
		return (FAILURE);
	element = &(map->grid[start->y][start->x - 1]);
	if (evaluate_node(head, element, end))
		return (FAILURE);
	element = &(map->grid[start->y + 1][start->x]);
	if (evaluate_node(head, element, end))
		return (FAILURE);
	return (SUCCESS);
}

t_map_element	*a_star_search(t_map_element *start, t_map_element *end, \
	t_map *map, t_resources *resources)
{
	t_double_list	*head;
	t_map_element	*element;

	if (start == NULL || end == NULL)
		return (NULL);
	head = NULL;
	element = start;
	element->evaluation = heuristic(element->x, element->y, end->x, end->y);
	element->visited = 1;
	while (element != NULL)
	{
		if (element == end)
		{
			double_list_free(head);
			return (element);
		}
		if (evaluate_around_nodes(&head, map, element, end))
		{
			double_list_free(head);
			raise_exception(EXCEPTION_SEARCH, resources);
		}
		element = double_list_pop_best(&head, &compare_elements);
	}
	return (NULL);
}
