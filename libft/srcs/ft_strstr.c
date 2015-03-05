/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:29:29 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:25:14 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	size_t		m_ctd;
	char		*m_start;
	size_t		i;

	if (!(m_ctd = ft_strlen(s2)))
		return ((char *)s1);
	if ((m_start = ft_strchr(s1, (int)*(s2))))
	{
		s1 = m_start;
		i = 0;
		while (s1[i] == s2[i] && s1[i] && s2[i])
		{
			m_ctd -= 1;
			i += 1;
		}
		if (m_ctd)
			return (ft_strstr(s1 + i, s2));
	}
	return (m_start);
}
