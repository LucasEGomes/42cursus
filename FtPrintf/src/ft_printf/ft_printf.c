/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:11:01 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/06 19:59:42 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_conversors(t_conversor *conversors)
{
	conversors[0] = print_percent_sign;
	conversors['c' - '%'] = print_char;
	conversors['s' - '%'] = print_string;
	conversors['p' - '%'] = print_pointer;
	conversors['d' - '%'] = print_decimal;
	conversors['i' - '%'] = print_integer;
	conversors['u' - '%'] = print_unsigned_decimal;
	conversors['x' - '%'] = print_lower_hexadecimal;
	conversors['X' - '%'] = print_upper_hexadecimal;
}

int	ft_printf(const char *format, ...)
{
	static t_conversor	conversors[84];
	va_list				ap;
	char				*conversion;
	char				*start;
	int					total;

	va_start(ap, format);
	if (conversors[0] == NULL)
		initialize_conversors(conversors);
	total = 0;
	start = (char *) format;
	conversion = next_conversion(start);
	while (conversion != NULL)
	{
		write(STDOUT_FILENO, start, conversion - start);
		total += conversion - start;
		total += conversors[(int)conversion[1] - '%'](ap);
		start = conversion + 2;
		conversion = next_conversion(start);
	}
	total += ft_strlen(start);
	ft_putstr_fd(start, STDOUT_FILENO);
	va_end(ap);
	return (total);
}
