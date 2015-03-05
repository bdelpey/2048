/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:08:29 by ffourati          #+#    #+#             */
/*   Updated: 2013/12/19 18:53:56 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = ft_strlen(s1);
	s1 += i;
	while (*s2 && n)
	{
		*(s1++) = *(s2++);
		n -= 1;
		i += 1;
	}
	*s1 = '\0';
	return (s1 - i);
}
