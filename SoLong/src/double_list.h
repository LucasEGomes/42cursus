/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:00:36 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/20 21:19:02 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LIST_H
# define DOUBLE_LIST_H

typedef struct s_double_list	t_double_list;
typedef struct s_double_list
{
	void			*content;
	t_double_list	*previous;
	t_double_list	*next;
}	t_double_list;

t_double_list	*double_list_new_node(void *content);
void			double_list_add_back(t_double_list **head, t_double_list *node);
void			*double_list_pop_best(t_double_list **head, \
	int (*compare)(void *, void *));
void			double_list_free(t_double_list *head);

#endif
