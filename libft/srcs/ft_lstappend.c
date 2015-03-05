/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 17:18:17 by ffourati          #+#    #+#             */
/*   Updated: 2014/04/26 18:03:18 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstappend(t_list **alst, t_list *lnk)
{
	t_list	*tmp;

	if (*alst == NULL)
	{
		*alst = lnk;
		return (0);
	}
	if (lnk == NULL)
		return (-1);
	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = lnk;
	return (0);
}
