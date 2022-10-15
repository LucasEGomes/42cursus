/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:56:55 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 22:17:43 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_utils.h"
#include <stdlib.h>

void	raise_exception(char *message)
{
	print_error(message);
	exit(1);
}
