/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:49:33 by ffourati          #+#    #+#             */
/*   Updated: 2014/05/16 23:54:58 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*nxt;

	tmp = *alst;
	while (tmp)
	{
		nxt = tmp->next;
		ft_lstdelone(&tmp, del);
		if (nxt)
			tmp = nxt;
	}
	*alst = NULL;
}
