/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:19:26 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/04 23:46:34 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H
# include "libft/libft.h"
# define CONVERSIONS "cspdiuxX%"

char	*next_conversion(char *string);
int		print_signed_int(int number);
int		print_char(char c);
int		print_percent_sign(void);
int		print_string(char *string);

#endif
