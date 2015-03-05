/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnkclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:48:46 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:51:23 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Pointed at as (*del) in ft_lstdel .
*/

void		ft_lnkclear(void *elem, size_t content_size)
{
	if (content_size && elem)
		ft_memdel(&elem);
}
