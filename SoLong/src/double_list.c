/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:01:40 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/28 18:56:32 by luceduar         ###   ########.fr       */
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
	if (node == *head)
		return ;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	(*head)->previous = node;
	node->next = *head;
	*head = node;
}

void	double_list_remove_node(t_double_list **head, t_double_list *node)
{
	if (node == *head)
		*head = node->next;
	else
	{
		node->previous->next = node->next;
		if (node->next != NULL)
			node->next->previous = node->previous;
	}
	if (*head != NULL)
		(*head)->previous = NULL;
}

void	*double_list_pop_best(t_double_list **head, \
	int (*compare)(void *, void *))
{
	t_double_list	*current;
	t_double_list	*best;
	void			*content;

	if (*head == NULL)
		return (NULL);
	best = *head;
	current = best->next;
	while (current != NULL)
	{
		if (compare(best->content, current->content) > 0)
			best = current;
		current = current->next;
	}
	content = best->content;
	double_list_remove_node(head, best);
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
