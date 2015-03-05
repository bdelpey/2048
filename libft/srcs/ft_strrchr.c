/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:30:45 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:28:33 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	end;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	s += end;
	while (end && *s != (char)c)
	{
		end -= 1;
		s -= 1;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
