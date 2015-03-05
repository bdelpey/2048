/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 21:17:29 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 19:55:10 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char const *s, size_t len)
{
	char	*nu;
	size_t	i;

	if (!(nu = (char *)ft_strnew(sizeof(char) * (len))))
		return (NULL);
	*(nu + len) = '\0';
	i = 0;
	while (i < len)
	{
		nu[i] = s[i];
		i += 1;
	}
	return (nu);
}
