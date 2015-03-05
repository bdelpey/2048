/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:24:21 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:20:12 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** dst must be the appropriate length to hold src.
*/

#include "libft.h"

void			ft_strrev(char *s)
{
	int			i;
	int			j;
	char		sw;

	i = 0;
	j = ft_strlen(s) - 1;
	if (j > 0)
	{
		while (i <= j)
		{
			sw = s[j];
			s[j] = s[i];
			s[i] = sw;
			j -= 1;
			i += 1;
		}
	}
}
