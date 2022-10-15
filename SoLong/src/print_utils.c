/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:12:51 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/14 22:16:12 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"
#include <unistd.h>

ssize_t	print_error(char *message)
{
	return (write(STDERR_FILENO, message, string_length(message)));
}
