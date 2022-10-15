/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:00:23 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/15 18:33:06 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H
# include <stdlib.h>

size_t	string_length(char *string);
char	*string_join(char *left, char *right);
int		string_ends_with(char *string, char *end);

#endif
