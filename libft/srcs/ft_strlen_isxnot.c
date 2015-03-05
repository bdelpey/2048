/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_isxnot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 08:47:55 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 21:11:20 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_isxnot(char not_, char c, int (*ft_is)(int))
{
	if (not_)
		return (!(*ft_is)((int)c));
	else
		return ((*ft_is)((int)c));
}

size_t		ft_strlen_isxnot(char const *s, char not_, int (*ft_is)(int))
{
	size_t	ct;

	ct = 0;
	while (*s && st_isxnot(not_, *s, (*ft_is)))
	{
		ct += 1;
		s += 1;
	}
	return (ct);
}
