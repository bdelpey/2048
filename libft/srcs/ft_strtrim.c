/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 09:40:23 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:22:45 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_getsubindex(char const *s, char rev_, size_t size)
{
	if (rev_)
	{
		size -= 1;
		while (ft_isspace((int)*(s + size)) && size)
			size -= 1;
	}
	else
	{
		size = 0;
		while (ft_isspace((int)*(s + size)))
			size += 1;
	}
	return (size);
}

char			*ft_strtrim(char const *s)
{
	size_t		index[2];
	size_t		len;
	char		i;

	len = ft_strlen(s);
	i = 2;
	while (i--)
		index[(unsigned int)i] = st_getsubindex(s, i, len);
	len = (index[1] - index[0]) + 1;
	if ((int)len < 0)
		len = 0;
	return (ft_strsub(s, index[0], len));
}
