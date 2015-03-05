/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:19:58 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:49:55 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstrepl_app(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;

	new = ft_lstnew((void const *)lst->content, lst->content_size);
	if (new != NULL)
		new = (*f)(new);
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*previous;
	t_list		*n_first;

	new = ft_lstrepl_app(lst, (*f));
	if (new == NULL)
	{
		ft_lstdel(&n_first, &ft_lnkclear);
		return (NULL);
	}
	n_first = new;
	previous = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new = ft_lstrepl_app(lst, (*f));
		if (new == NULL)
		{
			ft_lstdel(&n_first, &ft_lnkclear);
			return (NULL);
		}
		previous->next = new;
		previous = previous->next;
	}
	return (n_first);
}
