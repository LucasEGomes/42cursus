/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:01:40 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/20 21:19:18 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"
#include <stdlib.h>

t_double_list	*double_list_new_node(void *content)
{
	t_double_list	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (node);
	node->content = content;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

void	double_list_add_back(t_double_list **head, t_double_list *node)
{
	if (*head != NULL)
	{
		node->next = *head;
		(*head)->previous = node;
	}
	*head = node;
}

void	*double_list_pop_best(t_double_list **head, \
	int (*compare)(void *, void *))
{
	t_double_list	*current;
	t_double_list	*best;
	void			*content;

	if (*head == NULL)
		return (NULL);
	current = *head;
	best = *head;
	while (current->next != NULL)
	{
		if (compare(best->content, current->content) > 0)
			best = current;
		current = current->next;
	}
	if (best == *head)
		*head = best->next;
	else
		best->previous->next = best->next;
	content = best->content;
	free(best);
	return (content);
}

void	double_list_free(t_double_list *head)
{
	t_double_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
