/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 01:22:00 by ffourati          #+#    #+#             */
/*   Updated: 2014/04/17 01:40:26 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	st_abs(long int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

static void		st_putdigits_fd(long int n, int fd, ssize_t *ct, char *map)
{
	if (*ct < 0)
		return ;
	if (n >= 0x10 || (n < 0 && n <= -0x10))
		st_putdigits_fd(n / 0x10, fd, ct, map);
	if (ft_putchar_fd(map[st_abs(n % 0x10)], fd) > 0)
		*ct += 1;
	else
		*ct = -1;
}

ssize_t			ft_putlhex_fd(long int n, int fd)
{
	ssize_t		ct;
	char		*map;

	ct = 0;
	map = "0123456789ABCDEF";
	if (n < 0)
		ct += ft_putchar_fd('-', fd);
	ct += ft_putstr_fd("0x", fd);
	st_putdigits_fd(n, fd, &ct, map);
	return (ct);
}
