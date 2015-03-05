/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 04:40:27 by ffourati          #+#    #+#             */
/*   Updated: 2014/05/17 04:51:01 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_getdecimalsize(int n, int ret)
{
	if (n != 0)
		return (st_getdecimalsize(n / 10, ret + 1));
	return (ret);
}

static int		st_writedecimals(char *buf, int n)
{
	if (n != 0)
	{
		if (n > 0)
			*buf = (n % 10) + '0';
		else
			*buf = -(n % 10) + '0';
		return (st_writedecimals(buf - 1, n / 10));
	}
	return (0);
}

size_t			ft_itoa_r(int n, char *buf)
{
	int			dlen;

	dlen = (n != 0) ? st_getdecimalsize(n, 0) : 1;
	if (n < 0)
		dlen += 1;
	*buf = (n < 0) ? '-' : '0';
	dlen -= 1;
	if (n != 0)
		st_writedecimals(buf + dlen, n);
	return ((size_t)dlen);
}
