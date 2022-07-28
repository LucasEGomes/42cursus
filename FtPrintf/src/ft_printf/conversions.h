/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:19:26 by luceduar          #+#    #+#             */
/*   Updated: 2022/07/28 00:58:20 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H
# include "libft/libft.h"
# define CONVERSIONS "cspdiuxX%"

int		is_conversion(char *string);
char	*next_conversion(char *string);
int		signed_int_conversion(int number);

#endif
