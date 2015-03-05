/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:20:43 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/22 18:57:15 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t		ft_putstr_fd(char const *s, int fd)
{
	ssize_t	len;
	char	*err;

	if (s == NULL)
	{
		err = "(null)";
		len = (ssize_t)ft_strlen(err);
		len = write(fd, err, len);
	}
	else
	{
		len = (ssize_t)ft_strlen(s);
		len = write(fd, s, len);
	}
	return (len);
}
