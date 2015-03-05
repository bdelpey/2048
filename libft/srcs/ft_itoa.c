/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 19:23:55 by ffourati          #+#    #+#             */
/*   Updated: 2014/05/17 04:44:32 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_getdecimalsize(int n, int ret)
{
	if (n != 0)
		return (st_getdecimalsize(n / 10, ret + 1));
	return (ret);
}

static void		st_writedecimals(char *dstr, int n)
{
	if (n != 0)
	{
		if (n > 0)
			*dstr = (n % 10) + '0';
		else
			*dstr = -(n % 10) + '0';
		st_writedecimals(dstr - 1, n / 10);
	}
}

char			*ft_itoa(int n)
{
	int			dlen;
	char		*dstr;

	dlen = (n != 0) ? st_getdecimalsize(n, 0) : 1;
	if (n < 0)
		dlen += 1;
	dstr = ft_strnew(dlen);
	if (!dstr)
		return (NULL);
	*dstr = (n < 0) ? '-' : '0';
	dlen -= 1;
	if (n != 0)
		st_writedecimals(dstr + dlen, n);
	return (dstr);
}
