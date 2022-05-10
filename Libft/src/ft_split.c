/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:15 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 14:42:21 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_words(char **array, size_t words)
{
	size_t	index;

	index = 0;
	while (index <= words)
	{
		free(array[index]);
		index++;
	}
	free(array);
	return (NULL);
}

static char	**allocate_words(char **array, char const *s, char c)
{
	size_t	index;
	size_t	words;

	index = 0;
	words = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			if (index > 0)
			{
				array[words] = ft_substr(s, 0, index);
				if (array[words] == NULL)
					return (free_words(array, words));
				words++;
			}
			s = &s[index + 1];
			index = -1;
		}
		index++;
	}
	if (index > 0)
		array[words] = ft_substr(s, 0, index);
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char		**new_strings;
	size_t		words;
	size_t		index;
	char const	*aux;

	index = 0;
	words = 0;
	aux = s;
	while (aux[index] != '\0')
	{
		if (aux[index] == c)
		{
			if (index > 0)
				words++;
			aux = &aux[index + 1];
			index = -1;
		}
		index++;
	}
	if (index > 0)
		words++;
	new_strings = ft_calloc((words + 1), sizeof(*new_strings));
	if (new_strings == NULL)
		return (NULL);
	return (allocate_words(new_strings, s, c));
}
