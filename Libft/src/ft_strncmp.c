/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luceduar <luceduar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:28:53 by luceduar          #+#    #+#             */
/*   Updated: 2022/05/10 11:37:15 by luceduar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	if (n == 0)
		return (0);
	i = 0;
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while ((us1[i] == us2[i]) & (us1[i] != '\0') & (us2[i] != '\0') & \
		(i + 1 < n))
		i++;
	return (us1[i] - us2[i]);
}
