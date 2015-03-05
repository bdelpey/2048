/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:19:55 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 21:07:38 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	n = (n) ? n - 1 : n;
	while (n && *(const t_uchar *)s1 == *(const t_uchar *)s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((int)(*((const t_uchar *)s1) - *((const t_uchar *)s2)));
}
