/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:19:03 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 21:09:56 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char const	*uf_getnext_delim(char const *s, char delim)
{
	while (*s != delim && *s != '\0')
		s += 1;
	return (s);
}

static char const	*uf_getnext_sub(char const *s, char delim)
{
	while (*s == delim && *s != '\0')
		s += 1;
	return (s);
}

static int			uf_wordcount(char const *s, char delim)
{
	int		ct;

	ct = 0;
	while (*s)
	{
		s = uf_getnext_sub(s, delim);
		ct += 1;
		if (*s)
			s = uf_getnext_delim(s, delim);
	}
	return (ct);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tab;
	void		*start;
	int			ct;

	ct = uf_wordcount(s, c);
	tab = (char **)malloc(sizeof(char *) * (ct + 1));
	if (tab == NULL)
		return (NULL);
	start = &(*tab);
	while (tab)
	{
		s = uf_getnext_sub(s, c);
		*tab = ft_strsub(s, 0, uf_getnext_delim(s, c) - s);
		if (*tab == NULL)
			return (NULL);
		tab += 1;
		s = uf_getnext_delim(s, c);
		if (*s == '\0')
		{
			*tab = NULL;
			return ((char **)start);
		}
	}
	return ((char **)start);
}
