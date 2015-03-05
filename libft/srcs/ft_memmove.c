/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:32:39 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:41:57 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		uf_forwardcopy(t_uchar *s1, const t_uchar *s2, size_t n)
{
	while (n > 0)
	{
		*(s1++) = *(s2++);
		n -= 1;
	}
}

static void		uf_backwardcopy(t_uchar *s1, const t_uchar *s2, size_t n)
{
	s1 += n - 1;
	s2 += n - 1;
	while (n > 0)
	{
		*(s1--) = *(s2--);
		n -= 1;
	}
}

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (n && s1 != s2)
	{
		if (s2 < s1)
			uf_backwardcopy(s1, s2, n);
		else
			uf_forwardcopy(s1, s2, n);
	}
	return (s1);
}
