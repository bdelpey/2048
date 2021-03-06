/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:36:13 by ffourati          #+#    #+#             */
/*   Updated: 2014/03/27 20:35:53 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strequ(char const *s1, char const *s2)
{
	if (!(s1 && s2))
		return (0);
	while (*(s1) == *(s2) && *s1 && *s2)
	{
		s1 += 1;
		s2 += 1;
	}
	if (*(s1) == *(s2))
		return (1);
	else
		return (0);
}
