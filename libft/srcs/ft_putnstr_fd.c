/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 18:34:53 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/22 19:01:20 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_variadic_backends.h"

ssize_t			private_putnstr_fd(int fd, int argc, va_list ls)
{
	char const	*s;
	ssize_t		ret;

	ret = 0;
	while (argc-- > 0)
	{
		s = va_arg(ls, char const *);
		ret += ft_putstr_fd(s, fd);
	}
	return (ret);
}

ssize_t			ft_putnstr_fd(int fd, int argc, ...)
{
	va_list		ls;
	ssize_t		ret;

	va_start(ls, argc);
	ret = private_putnstr_fd(fd, argc, ls);
	va_end(ls);
	return (ret);
}
