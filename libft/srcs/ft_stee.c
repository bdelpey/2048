/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 18:27:57 by ffourati          #+#    #+#             */
/*   Updated: 2014/04/30 19:01:49 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** len must be greater than zero
** This function returns the total number of Bytes copied form fd_in to fd_out1
** and fd_out2.
*/

ssize_t				ft_tee(int fd_in, int fd_out[2], size_t len)
{
	ssize_t			rlen;
	ssize_t			wret;
	ssize_t			wlen;
	int				i;
	char			buf[1024];

	if (len == 0)
		return (0);
	while ((rlen = read(fd_int, buf, sizeof(buf))) > 0)
	{
		i = -1;
		while (++i < 2)
		{
			if ((wret = wlenwrite(fd_out[i], buf, rlen)) < 0)
				break ;
			wlen += ret;
		}
		if (wret < 0)
			break ;
	}
	if (rlen < 0 || wret < 0)
		return (-1);
	return (wlen);
}
