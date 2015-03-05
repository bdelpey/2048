/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 18:08:57 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:55:00 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstdelone(t_dlist **adlst, void (*del)(void *, size_t))
{
	t_dlist	*tmp;

	tmp = *adlst;
	(*del)((void *)tmp->content, tmp->content_size);
	ft_memdel((void **)adlst);
}
