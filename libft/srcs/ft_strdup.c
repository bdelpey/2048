/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:39:22 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 21:07:56 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	char			*dup;
	char			**begin;
	size_t			len;
	size_t			i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	i = 0;
	dup = (char *)ft_memalloc(sizeof(char) * len);
	begin = &dup;
	if (dup)
	{
		while (i < len)
		{
			dup[i] = s1[i];
			i++;
		}
	}
	return (*begin);
}
