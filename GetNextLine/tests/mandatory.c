/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:23:25 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/13 16:41:54 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

int	main(int argc, char **argv)
{
	int		file_descriptor;
	ssize_t	read_bytes;
	
	file_descriptor = 0;
	if (argc > 1)
		file_descriptor = open(argv[1], O_RDONLY);
	read_bytes = read(file_descriptor, NULL, 0);
	printf("File opened. Fd: %d, Read: %ld.\n", file_descriptor, read_bytes);
	close(file_descriptor);
	printf("File closed.\n");
	return (EXIT_SUCCESS);
}
