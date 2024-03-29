/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:05:16 by luceduar          #+#    #+#             */
/*   Updated: 2022/08/05 22:14:18 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include "libft/libft.h"

char	*ft_uitoa_base(unsigned int number, char *base);
char	*ft_sizetoa_base(size_t number, char *base);

#endif
