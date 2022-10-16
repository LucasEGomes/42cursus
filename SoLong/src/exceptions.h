/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:03:18 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/16 17:20:18 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_H
# define EXCEPTIONS_H
# define EXCEPTION_ARGUMENTS "Invalid number of arguments.\
 The program takes one map filename as argument.\n"
# define EXCEPTION_MAP_FORMAT "Invalid map format.\
 Map must have extension '*.ber'.\n"
# define EXCEPTION_DISPLAY "Failed to create display.\n"
# define EXCEPTION_WINDOW "Failed to create window.\n"
# define EXCEPTION_LOAD_ASSETS "Failed to load all assets.\n"
# define EXCEPTION_READ_MAP "Failed to read map file.\n"
# define EXCEPTION_RECTANGULAR "Map must be rectangular.\n"
# define EXCEPTION_MINIMAL_ELEMENTS "Map must have 1 exit, 1 start position,\
 and at least 1 collectible.\n"
# define EXCEPTION_INVALID_VALUE "File has invalid content.\
 Expected only '0' for background,\
 '1' for walls,\
 'C' for collectible,\
 'E' for collectible, and\
 'P' for starting position."
# include "shared.h"

void	raise_exception(char *message, t_resources *resources) \
	__attribute__ ((noreturn));
void	raise_file_exception(char *message, char *content, \
	t_resources *resources) __attribute__ ((noreturn));

#endif
