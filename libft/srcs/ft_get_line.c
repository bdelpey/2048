/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 03:23:40 by ffourati          #+#    #+#             */
/*   Updated: 2015/02/23 19:06:11 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int					f_read_batch(char **batch, int fd)
{
	int						ret;

	if ((*batch = ft_strnew(LINE_READ_MAX)) == NULL)
		return (-1);
	ret = read(fd, *batch, LINE_READ_MAX);
	return (ret);
}

static int					f_extract(t_line *meta)
{
	meta->tail = ft_strchr(meta->head);
	if (meta->tail == NULL)
	{
		meta->next = meta->raw;
		return (0);
	}
}

int							ft_get_line(int fd, char **line)
{
	int						rd_re;
	static struct s_line	meta = {NULL, NULL, NULL, NULL};

	if (meta->raw == NULL)
	{
		if ((rd_re = f_read_batch(&meta->raw, fd)) == -1)
		{
			ft_bzero(&meta, sizeof(struct s_line));
			return (-1);
		}
		meta->head = meta->raw;
	}
}
