/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 03:10:45 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/24 20:46:30 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** _old_size_ : length of block pointed to by _p_, to copy over the fresh block.
** With a length of 0, ft_realloc will copy _new_size_ over, which is unsecure.
*/

void				*ft_realloc(void *p, size_t old_size, size_t new_size)
{
	void			*nu;

	if (new_size == 0)
		return (NULL);
	if (old_size == new_size)
		return (p);
	if ((nu = malloc(new_size)) == NULL)
		return (NULL);
	if (p != NULL)
	{
		ft_memcpy(nu, p, old_size);
		free(p);
	}
	return (nu);
}
