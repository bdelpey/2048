/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtputlhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 19:35:22 by ffourati          #+#    #+#             */
/*   Updated: 2014/04/26 19:54:17 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t			ft_fmtputlhex(long int n, int format)
{
	return (ft_fmtputlhex_fd(n, 1, format));
}
