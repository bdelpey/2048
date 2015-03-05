/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 03:29:31 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/21 03:51:13 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static size_t	f_joint_length(int argc, va_list ls)
{
	size_t		len;
	va_list		cp;
	char		*s;

	len = 0;
	va_copy(cp, ls);
	while (argc--)
	{
		s = va_arg(cp, char *);
		len += ft_strlen(s);
	}
	va_end(cp);
	return (len);
}

char			*ft_strnjoin(int argc, ...)
{
	char		*nu;
	char		*s;
	va_list		ls;
	size_t		len;

	va_start(ls, argc);
	len = f_joint_length(argc, ls);
	if ((nu = ft_strnew(len)) == NULL)
		return (NULL);
	while (argc--)
	{
		s = va_arg(ls, char *);
		ft_strcat(nu, s);
	}
	va_end(ls);
	return (nu);
}
