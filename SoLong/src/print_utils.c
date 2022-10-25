/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:12:51 by luceduar          #+#    #+#             */
/*   Updated: 2022/10/22 15:12:46 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_utils.h"
#include "string_utils.h"
#include <unistd.h>

ssize_t	print_error(char *message)
{
	return (write(STDERR_FILENO, message, string_length(message)));
}

ssize_t	print_message(char *message)
{
	return (write(STDOUT_FILENO, message, string_length(message)));
}

ssize_t	print_number(int number)
{
	char	digits[9];
	int		index;

	if (number == 0)
		return (write(STDOUT_FILENO, "0\n", 2));
	index = 6;
	digits[8] = '\0';
	digits[7] = '\n';
	while (number != 0)
	{
		digits[index--] = number % 10 + '0';
		number /= 10;
	}
	index++;
	return (write(STDOUT_FILENO, digits + index, 8 - index));
}
