/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:46:06 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 22:06:52 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exceptions.h"

void	check_arguments_number(int argc)
{
	if (argc != 2)
		raise_exception("Invalid number of arguments." \
			"The program takes one map filename as argument.");
}

void	check_map_filename(char *filename)
{
	if (!string_ends_with(filename, ".ber"))
		raise_exception("Invalid map format. Map must have extension '*.ber'.");
}

void	check_arguments(int argc, char **argv)
{
	check_arguments(argc);
	check_map_filename(argv[1]);
}
