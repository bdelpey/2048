/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 18:00:01 by ffourati          #+#    #+#             */
/*   Updated: 2013/12/19 18:36:20 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstadd(t_dlist **adlst, t_dlist *new)
{
	(*adlst)->prev = new;
	new->next = *adlst;
	*adlst = new;
}
