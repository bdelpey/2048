/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 18:29:53 by ffourati          #+#    #+#             */
/*   Updated: 2013/12/24 14:19:05 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void		ft_dlstdel(t_dlist **adlst, void (*del)(void *, size_t))
{
	t_dlist	*tmp;
	t_dlist	*nxt;

	tmp = (*adlst)->prev;
	if (tmp)
		tmp->next = NULL;
	tmp = *adlst;
	while (tmp)
	{
		nxt = tmp->next;
		ft_dlstdelone(&tmp, (*del));
		if (tmp)
			tmp = nxt;
	}
	*adlst = NULL;
}
