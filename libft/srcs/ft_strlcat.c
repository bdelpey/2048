/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:20:18 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:33:14 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	dst += dst_len;
	if (size < dst_len)
		dst_len -= (dst_len - size);
	size = size - dst_len - 1;
	if ((long int)size > 0)
	{
		while (*src && size)
		{
			*(dst++) = *(src++);
			size -= 1;
		}
		*dst = '\0';
	}
	return (dst_len + src_len);
}
