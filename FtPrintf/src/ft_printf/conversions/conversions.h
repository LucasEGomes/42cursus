/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:19:26 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/07 18:07:02 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H
# include "libft/libft.h"
# include "ft_printf/ft_printf_utils.h"
# include <stdarg.h>
# define CONVERSIONS "cspdiuxX%"

char	*next_conversion(char *string);
int		print_char(va_list ap);
int		print_string(va_list ap);
int		print_pointer(va_list ap);
int		print_decimal(va_list ap);
int		print_integer(va_list ap);
int		print_unsigned_decimal(va_list ap);
int		print_lower_hexadecimal(va_list ap);
int		print_upper_hexadecimal(va_list ap);
int		print_percent_sign(va_list ap);

#endif
