/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:03:00 by mascote           #+#    #+#             */
/*   Updated: 2022/04/06 00:04:25 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

static int	too_many_arguments_error(void)
{
	ft_putstr("Too many arguments.\n");
	return (0);
}

static int	file_is_missing_error(void)
{
	ft_putstr("File name missing.\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int	file_descriptor;

	if (argc < 2)
		return (file_is_missing_error());
	if (argc > 2)
		return (too_many_arguments_error());
	file_descriptor = open(argv[1], O_RDONLY);
	read_file(file_descriptor);
	close(file_descriptor);
	write(1, "\n", 1);
	return (0);
}
