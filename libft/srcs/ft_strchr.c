/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:31:41 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:39:25 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (*s != (char)c && len)
	{
		s += 1;
		len -= 1;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
