/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:28:03 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/22 19:20:39 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

static void		st_putdigits_fd(int n, int fd, ssize_t *ct)
{
	if (*ct < 0)
		return ;
	if (n >= 10 || (n < 0 && n <= -10))
		st_putdigits_fd(n / 10, fd, ct);
	if (ft_putchar_fd(st_abs(n % 10) + '0', fd) > 0)
		*ct += 1;
	else
		*ct = -1;
}

ssize_t			ft_putnbr_fd(int n, int fd)
{
	ssize_t		ct;

	ct = 0;
	if (n < 0)
		ct += ft_putchar_fd('-', fd);
	st_putdigits_fd(n, fd, &ct);
	return (ct);
}
