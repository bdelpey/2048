/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:17:28 by ffourati          #+#    #+#             */
/*   Updated: 2013/12/31 12:32:03 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = b;
	i = 0;
	while (tmp && i < len)
	{
		*(tmp + i) = (unsigned char)c;
		i += 1;
	}
	return (b);
}
