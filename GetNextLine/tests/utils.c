/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:19:08 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/05 21:45:18 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*free_lines(char **lines)
{
	ssize_t	line;

	line = 0;
	while (lines[line] != NULL)
	{
		free(lines[line]);
		line++;
	}
	free(lines);
	return (NULL);
}

char	**alloc_lines(char *text)
{
	ssize_t	count;
	ssize_t	index;
	char	**lines;

	index = 0;
	count = 0;
	while (text[index] != '\0')
	{
		if (text[index] == '\n')
			count++;
		index++;
	}
	if (index > 0 && text[index - 1] != '\n')
		count++;
	lines = malloc(sizeof(*lines) * (count + 1));
	if (lines == NULL)
		return (NULL);
	lines[count] = NULL;
	return (lines);
}

char	**get_lines(char *text)
{
	ssize_t	index;
	ssize_t	line;
	char	**lines;

	lines = alloc_lines(text);
	if (lines == NULL)
		return (NULL);
	index = 0;
	line = 0;
	while (text[index] != '\0')
	{
		if (text[index] == '\n')
		{
			lines[line] = ft_substr(text, 0, index + 1);
			if (lines[line] == NULL)
				return (free_lines(lines));
			if (lines[line][index] == '\n' && lines[line][index - 1] == '$')
			{
				lines[line][index - 1] = '\n';
				lines[line][index] = '\0';
			}
			else if (lines[line][index] == '$')
				lines[line][index] = '\n';
			text += index + 1;
			index = 0;
			line += 1;
		}
		index++;
	}
	if (index > 0)
	{
		lines[line] = ft_substr(text, 0, index + 1);
		if (lines[line] == NULL)
			return (free_lines(lines));
		if (lines[line][index - 1] == '\n' && lines[line][index - 2] == '$')
		{
			lines[line][index - 2] = '\n';
			lines[line][index - 1] = '\0';
		}
		else if (lines[line][index - 1] == '$')
			lines[line][index - 1] = '\n';
	}
	return (lines);
}

void	print_message(char *filename, int result)
{
	char	*message;
	char	*file;

	message = FG_GREEN "%s-OK  " FG_RESET;
	if (result < 0)
		message = FG_YELLOW "%s-SKIP" FG_RESET;
	if (result > 0)
		message = FG_RED "%s-KO  " FG_RESET;
	file = ft_strchr(filename, '/');
	if (file == NULL)
		dprintf(1, message, filename);
	else
		dprintf(1, message, file + 1);
}
