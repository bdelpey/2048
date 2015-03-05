/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:10:50 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:40:35 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include <string.h>
#elif defined __linux__
# include <stdio.h>
#endif

void				ft_memrev(void *seg, size_t len)
{
	ssize_t			i;
	ssize_t			j;
	unsigned char	swap;

	i = 0;
	j = (ssize_t)len - 1;
	while (i <= j)
	{
		swap = ((unsigned char *)seg)[j];
		((unsigned char *)seg)[j] = ((unsigned char *)seg)[i];
		((unsigned char *)seg)[i] = swap;
		j -= 1;
		i += 1;
	}
}
