/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 18:01:09 by ffourati          #+#    #+#             */
/*   Updated: 2013/12/19 18:37:14 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstins(t_dlist **pr_dlst, t_dlist *lnk, t_dlist **nx_dlst)
{
	(*pr_dlst)->next = lnk;
	(*nx_dlst)->prev = lnk;
	lnk->prev = *pr_dlst;
	lnk->next = *nx_dlst;
}
