/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tee_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 18:27:57 by ffourati          #+#    #+#             */
/*   Updated: 2014/05/04 14:50:56 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** len must be greater than zero
** This function returns the total number of Bytes copied form fd_in to fd_out1
** and fd_out2.
*/

ssize_t				ft_tee_s(int fd_in, int fd_out[], int nfds)
{
	ssize_t			rlen;
	ssize_t			wret;
	ssize_t			wlen;
	int				i;
	char			buf[MEBIO(2)];

	if (nfds <= 0)
		return (0);
	wlen = 0;
	wret = 0;
	if ((rlen = read(fd_in, buf, sizeof(buf) - 1)) > 0)
	{
		i = -1;
		while (++i < nfds)
		{
			if ((wret = write(fd_out[i], buf, rlen)) < 0)
				return (-1);
			wlen += wret;
		}
	}
	if (rlen < 0 || wret < 0)
		return (-1);
	return (wlen);
}
