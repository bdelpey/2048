/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtputlhex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 01:22:00 by ffourati          #+#    #+#             */
/*   Updated: 2014/05/11 19:23:19 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	f_abs(long int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

static void		putdigits_fd(long int n, int fd, ssize_t *ct, char *map)
{
	if (*ct < 0)
		return ;
	if (n >= 0x10 || (n < 0 && n <= -0x10))
		putdigits_fd(n / 0x10, fd, ct, map);
	if (ft_putchar_fd(map[f_abs(n % 0x10)], fd) > 0)
		*ct += 1;
	else
		*ct = -1;
}

static ssize_t	leading_zeros(long int n, int fd)
{
	long int	ref;
	int			z;
	char		pattern[24];
	ssize_t		ct;

	z = 0;
	ref = 0x7fffffffffffffff;
	ref += (n < 0) ? 1 : 0;
	ct = 0;
	ft_memset((char *)pattern, '0', sizeof(pattern));
	while (42)
	{
		ref /= 0x10;
		if ((ref > n && n > 0) || (ref < n && n < 0))
			z++;
		else
			break ;
	}
	pattern[z] = '\0';
	ct += ft_putstr_fd(pattern, fd);
	return (ct);
}

ssize_t			ft_fmtputlhex_fd(long int n, int fd, int format)
{
	ssize_t		ct;
	char		*map;

	ct = 0;
	map = "0123456789ABCDEF";
	if (n < 0)
		ct += ft_putchar_fd('-', fd);
	if (format & 0xFF00)
		ct += ft_putstr_fd("0x", fd);
	if (format & 0xFF)
		ct += leading_zeros(n, fd);
	putdigits_fd(n, fd, &ct, map);
	return (ct);
}
