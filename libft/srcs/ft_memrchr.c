/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:08:23 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 21:12:09 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void				*ft_memrchr(const void *s, int c, size_t n)
{
	void const		*p;

	if (n > 0)
	{
		p = s + n - 1;
		while (p >= s)
		{
			if (*(const unsigned char *)p == (unsigned char)c)
				return ((void *)p);
			--p;
		}
	}
	return ((void *)0);
}
