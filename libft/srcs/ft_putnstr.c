/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 18:38:38 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/22 18:57:59 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_variadic_backends.h"

ssize_t			ft_putnstr(int argc, ...)
{
	va_list		ls;
	ssize_t		ret;

	va_start(ls, argc);
	ret = private_putnstr_fd(1, argc, ls);
	va_end(ls);
	return (ret);
}
