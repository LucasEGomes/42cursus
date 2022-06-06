/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:08:59 by luceduar          #+#    #+#             */
/*   Updated: 2022/06/05 21:45:10 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "libft.h"
# include "colors.h"
# include <stdlib.h>
# include <stdio.h>

void	*free_lines(char **lines);
char	**alloc_lines(char *text);
char	**get_lines(char *text);
void	print_message(char *filename, int result);

#endif
