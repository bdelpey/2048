/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:24:40 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/22 18:33:17 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putendl_fd(char const *s, int fd)
{
	ssize_t	len;

	len = ft_putstr_fd(s, fd);
	if (ft_putchar_fd('\n', fd) < 0)
		return (-1);
	return (len + 1);
}
