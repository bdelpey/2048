/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:19:03 by ffourati          #+#    #+#             */
/*   Updated: 2014/01/02 18:56:30 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Read (*r) as being a pointer to a function int is_trash(int) returning 1 if
** *s is a delim and 0 else (i.e.: a token).
*/

/*
** Lacks the ability to handle quotation marks, escape chars, and
** the room to implement it.
*/

static int		uf_reach_next(char *s, char not_, int (*r)(int))
{
	int			incr;

	incr = 0;
	if (not_)
	{
		while (s[incr] != '\0' && !(*r)((int)s[incr]))
			incr += 1;
	}
	else
	{
		while (s[incr] != '\0' && (*r)((int)s[incr]))
			incr += 1;
	}
	return (incr);
}

static int		uf_reach_next_token(char *s, int (*r)(int))
{
	return (uf_reach_next(s, 1, r));
}

static int		uf_reach_next_trash(char *s, int (*r)(int))
{
	return (uf_reach_next(s, 0, r));
}

static int		uf_count_tokens(char *s, int (*r)(int))
{
	int			ct;

	ct = 0;
	while (*s != '\0')
	{
		if ((*r)((int)*s) == 0)
		{
			ct += 1;
			s += uf_reach_next_trash(s, r);
		}
		else
			s += uf_reach_next_token(s, r);
	}
	return (ct);
}

char			**ft_lex_rule(char const *src, int (*is_delim)(int))
{
	int			tokens;
	char		scpy[ft_strlen(src)];
	char		**t_ar;
	int			ix[2];

	p_scpy = ft_strncpy(scpy, src, ft_strlen(src));
	tokens = uf_count_tokens(scpy, is_delim);
	if ((t_ar = (char **)malloc(sizeof(char *) * (tokens + 1))) == NULL)
		return (NULL);
	t_ar[tokens] = NULL;
	ix[0] = 0;
	ix[1] = 0;
	while (ix[0] < tokens)
	{
		ix[1] += uf_reach_next_token(scpy, r);
		if ((t_ar[ix[0]++] = ft_strdup(scpy[ix[1]])) == NULL)
		{
			while (--ix[0] >= 0)
				free(t_ar[ix[0]]);
			return (NULL);
		}
		ix[1] += uf_reach_next_trash(scpy, r);
	}
	return (t_ar);
}
