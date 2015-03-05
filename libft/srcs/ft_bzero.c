/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:15:19 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:55:31 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		if (n >= sizeof(unsigned long))
		{
			*(((unsigned long *)s)) = 0UL;
			n -= sizeof(unsigned long);
			s += sizeof(unsigned long);
		}
		else if (n >= sizeof(unsigned int))
		{
			*(((unsigned int *)s)) = 0U;
			n -= sizeof(unsigned int);
			s += sizeof(unsigned int);
		}
		else
		{
			*(((unsigned char *)s)) = '\0';
			n -= sizeof(unsigned char);
			s += sizeof(unsigned char);
		}
	}
}
