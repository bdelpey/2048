/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:37:36 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:24:24 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	new = ft_strnew(len);
	if (new && len)
	{
		i = 0;
		while (s[start + i] && i < len)
		{
			new[i] = s[start + i];
			i += 1;
		}
	}
	return (new);
}
