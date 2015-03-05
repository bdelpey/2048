/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inssort_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 13:11:26 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 19:52:52 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include <string.h>
#elif defined __linux__
# include <stdio.h>
#endif
#include "libft.h"

void		ft_inssort_strings(char **av, size_t size)
{
	ssize_t		i;
	ssize_t		hole_i;
	char		*tmp;

	if (size <= 1)
		return ;
	i = 0;
	while ((size_t)i < size)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			hole_i = i + 1;
			while (i >= 0 && ft_strcmp(av[hole_i], av[i]) > 0)
				i -= 1;
			tmp = av[i];
			av[i] = av[hole_i];
			av[hole_i] = tmp;
			i = 0;
		}
		else
			i += 1;
	}
}
