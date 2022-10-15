/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:56:55 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 22:43:04 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exceptions.h"
#include "print_utils.h"
#include <stdlib.h>

void	raise_exception(char *message)
{
	print_error(message);
	exit(1);
}
