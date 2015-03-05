/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:35:40 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:32:04 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_n;
	size_t	ct;

	if (!(s && f))
		return (NULL);
	ct = 0;
	s_n = ft_strnew(ft_strlen(s) + 1);
	if (s_n)
	{
		while (s[ct])
		{
			s_n[ct] = (*f)(ct, s[ct]);
			ct += 1;
		}
	}
	return (s_n);
}
