/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:57:22 by ffourati          #+#    #+#             */
/*   Updated: 2014/04/26 18:01:48 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstadd(t_list **alst, t_list *lnk)
{
	if (*alst == NULL)
	{
		*alst = lnk;
		return (0);
	}
	if (lnk == NULL)
		return (-1);
	lnk->next = *alst;
	*alst = lnk;
	return (0);
}
