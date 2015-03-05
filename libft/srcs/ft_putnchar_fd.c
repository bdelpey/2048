/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:49:47 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/22 19:24:01 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putnchar_fd(char *s, size_t n, int fd)
{
	ssize_t	ct;

	ct = 0;
	while ((size_t)ct < n)
	{
		if (ft_putchar_fd(*s, fd) < 0)
			return (-1);
		ct += 1;
		s += 1;
	}
	return (ct);
}
