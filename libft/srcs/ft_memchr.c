/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:08:23 by ffourati          #+#    #+#             */
/*   Updated: 2015/02/23 19:05:19 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(const unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		++s;
		--n;
	}
	return ((void *)0);
}
