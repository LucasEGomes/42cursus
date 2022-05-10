/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:15 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/09 22:29:16 by luceduar         ###   ########.fr       */
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
			array[words] = ft_substr(s, 0, index);
			if (array[words] == NULL)
				return (free_words(array, words));
			words++;
			s = s + index;
			index = 0;
		}
		index++;
	}
	array[words] = ft_substr(s, 0, index);
	words++;
	array[words] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**new_strings;
	size_t	words;
	size_t	index;

	index = 0;
	words = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			words++;
		index++;
	}
	new_strings = malloc(sizeof(*new_strings) * (words) + 1);
	if (new_strings)
		return (NULL);
	return (allocate_words(new_strings, s, c));
}
