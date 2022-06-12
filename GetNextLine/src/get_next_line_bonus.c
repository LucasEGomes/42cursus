/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:35 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/11 14:39:18 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_node	*new_node(int file_descriptor)
{
	t_node		*node;
	t_buffer	*buffer;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	buffer = malloc(sizeof(*buffer));
	if (buffer == NULL)
	{
		free(node);
		return (NULL);
	}
	node->file_descriptor = file_descriptor;
	node->next = NULL;
	buffer->string = NULL;
	buffer->size = 0;
	node->buffer = buffer;
	return (node);
}

static void	add_node(t_node **root, t_node *node)
{
	t_node	*current;

	if (*root == NULL)
	{
		*root = node;
		return ;
	}
	current = *root;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
}

static void	*free_node(t_node **root, int file_descriptor)
{
	t_node	*previous;
	t_node	*current;

	previous = NULL;
	current = *root;
	while (current != NULL && current->file_descriptor != file_descriptor)
	{
		previous = current;
		current = current->next;
	}
	if (previous == NULL)
		*root = current->next;
	else
		previous->next = current->next;
	free(current->buffer);
	free(current);
	return (NULL);
}

static t_buffer	*get_buffer_by_file_descriptor(t_node **root, int fd)
{
	t_node	*node;

	node = *root;
	while (node != NULL && node->file_descriptor != fd)
		node = node->next;
	if (node == NULL)
	{
		node = new_node(fd);
		add_node(root, node);
	}
	construct_buffer(node->buffer, fd);
	return (node->buffer);
}

char	*get_next_line(int fd)
{
	static t_node		*root;
	t_buffer			*buffer;
	char				*line;
	ssize_t				index;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = get_buffer_by_file_descriptor(&root, fd);
	if (buffer->string == NULL || buffer->size <= 0)
		return (free_node(&root, fd));
	index = 0;
	line = NULL;
	while (buffer->size > 0 && buffer->string[index++] != '\n')
	{
		if (index == buffer->size)
		{
			line = append_buffer(line, buffer, index);
			if (line == NULL)
				return (NULL);
			index = 0;
			buffer->size = read(fd, buffer->string, BUFFER_SIZE);
		}
	}
	return (append_buffer(line, buffer, index));
}
