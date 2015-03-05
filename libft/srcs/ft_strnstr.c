/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:28:50 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:29:41 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		m_ctd;
	char		*m_start;
	size_t		i;

	if (!(m_ctd = ft_strlen(s2)))
		return ((char *)s1);
	m_start = ft_strchr(s1, (int)*(s2));
	if (((long int)(n = n - (m_start - s1)) > 0 && m_start))
	{
		s1 = m_start;
		i = 0;
		while (s1[i] == s2[i] && s1[i] && s2[i] && n > 0)
		{
			m_ctd -= 1;
			i += 1;
			n -= 1;
		}
		if (m_ctd && n > 0)
			return (ft_strnstr(s1 + i, s2, n - i));
		if (m_ctd && n == 0)
			return (NULL);
	}
	else
		m_start = NULL;
	return (m_start);
}
