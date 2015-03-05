/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 17:46:19 by ffourati          #+#    #+#             */
/*   Updated: 2013/12/19 18:19:20 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist		*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist		*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->content = malloc(content_size);
	if (new->content == NULL)
	{
		free(new);
		return (NULL);
	}
	if (content != NULL)
	{
		new->content = ft_memmove(new->content, content, content_size);
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
