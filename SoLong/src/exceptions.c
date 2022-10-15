/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:56:55 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/15 02:48:50 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exceptions.h"
#include "print_utils.h"
#include "free_resources.h"
#include <stdlib.h>

void	raise_exception(char *message, t_resources	*resources)
{
	if (resources != NULL)
		free_resources(resources);
	print_error("Error\n");
	print_error(message);
	exit(1);
}
