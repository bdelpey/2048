/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:16:24 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:47:36 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	t_uchar			*dst;
	const t_uchar	*src;
	t_uchar			ch;

	dst = (t_uchar *)s1;
	src = (const t_uchar *)s2;
	ch = (t_uchar)c;
	while (*src != ch && n > 0)
	{
		*dst = *src;
		dst += 1;
		src += 1;
		n -= 1;
	}
	if (*src == ch)
	{
		*dst = *src;
		return ((void *)(dst + 1));
	}
	return (NULL);
}
