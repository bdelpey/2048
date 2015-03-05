/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:25:34 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:56:03 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		n;
	char	neg_;

	n = 0;
	while (ft_isspace((int)*str))
		str += 1;
	neg_ = (*str) != '-' ? 0 : 1;
	if (neg_ || *str == '+')
		str += 1;
	if (ft_isdigit((int)*str))
	{
		while (ft_isdigit((int)*str) && *str)
		{
			n = (n * 10) + (*str - '0');
			str += 1;
		}
		if (neg_)
			n *= -1;
	}
	return (n);
}
