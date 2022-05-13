/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:23:25 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/13 16:19:00 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

int	main(int argc, char **argv)
{
	int	file_descriptor;
	
	file_descriptor = 0;
	if (argc > 1)
		file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor < 0)
		return (EXIT_FAILURE);
	printf("File opened. Fd: %d.\n", file_descriptor);
	close(file_descriptor);
	printf("File closed.\n");
	return (EXIT_SUCCESS);
}
