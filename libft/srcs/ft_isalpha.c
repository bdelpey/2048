/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:49:18 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:53:46 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return ((t_uchar)c >= 'A' && (t_uchar)c <= 'Z');
}

static int	ft_islower(int c)
{
	return ((t_uchar)c >= 'a' && (t_uchar)c <= 'z');
}

int			ft_isalpha(int c)
{
	if (c < 00 || c > 0177)
		c = EOF;
	return (ft_isupper(c) || ft_islower(c));
}
