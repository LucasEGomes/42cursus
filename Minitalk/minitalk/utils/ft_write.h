/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:06:46 by luceduar          #+#    #+#             */
/*   Updated: 2022/12/10 08:06:46 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITE_H
# define FT_WRITE_H
# include <unistd.h>

void	ft_write(int fd, const void *buffer, size_t size);

#endif
