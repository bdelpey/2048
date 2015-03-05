/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:22:51 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:37:18 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *s1, const char *s2)
{
	t_uint	i;

	i = 0;
	if (s1 && s2)
	{
		while (*(s2 + i))
		{
			*(s1 + i) = *(s2 + i);
			i += 1;
		}
		*(s1 + i) = *(s2 + i);
	}
	return (s1);
}
