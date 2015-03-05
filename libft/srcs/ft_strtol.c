/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 12:19:10 by ffourati          #+#    #+#             */
/*   Updated: 2014/04/17 01:21:07 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strtox.h"

/*
** TODO:
** Binary, Octal, Decimal
** Base guessing with base == 0
*/

/*
** PROBLEM : every 0x10 'num' value gets + 1 inaccuracy if not subtracted
** by 'num' -> dirty fix
*/

long int			ft_strtol(const char *nptr, char **endptr, int base)
{
	char			sign;
	long int		num;
	char			*cmap;

	if (g_conv_map[base] == NULL)
		return (0);
	while (*nptr != '\0' && ft_isspace((int)*nptr))
		nptr++;
	sign = (*nptr == '-') ? -1 : 1;
	nptr += (*nptr == '-' || *nptr == '+') ? 1 : 0;
	num = ft_strlen(g_conv_map[base]->prefix);
	if (ft_strncmp(nptr, g_conv_map[base]->prefix, num) == 0)
		nptr += num;
	num = 0;
	cmap = (char *)g_conv_map[base]->charmap;
	while (*nptr != '\0' && cmap[(unsigned int)*nptr] != 0)
	{
		num += (num * base) + ((long int)cmap[(unsigned char)*nptr] - 1L - num);
		nptr++;
	}
	num = (sign < 0) ? -num : num;
	if (endptr != NULL)
		*endptr = (char *)nptr;
	return (num);
}
