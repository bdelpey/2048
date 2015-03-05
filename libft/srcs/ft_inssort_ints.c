/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inssort_ints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 13:11:26 by ffourati          #+#    #+#             */
/*   Updated: 2014/02/07 19:26:41 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_inssort_ints(int **av, int size)
{
	int		i;
	int		hole_i;
	int		tmp;

	if (size <= 1)
		return ;
	i = 0;
	size -= 1;
	while (i < size)
	{
		if (av[0][i] <= av[0][i + 1])
			i += 1;
		else
		{
			hole_i = i + 1;
			while (av[0][hole_i] > av[0][i] && i >= 0)
				i -= 1;
			tmp = av[0][i];
			av[0][i] = av[0][hole_i];
			av[0][hole_i] = tmp;
			i = 0;
		}
	}
}
