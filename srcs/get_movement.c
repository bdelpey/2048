/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:45:19 by ffourati          #+#    #+#             */
/*   Updated: 2015/03/01 18:51:21 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int				walk_down(int from, int sq_side)
{
	int					to;

	to = from + sq_side;
	if (to < sq_side * sq_side)
		return (to);
	else
		return (-1);
}

static int				walk_up(int from, int sq_side)
{
	int					to;

	to = from - sq_side;
	if (to >= 0)
		return (to);
	else
		return (-1);
}

static int				walk_left(int from, int sq_side)
{
	if (from % sq_side)
		return (from - 1);
	else
		return (-1);
}

static int				walk_right(int from, int sq_side)
{
	if (from % sq_side != sq_side - 1)
		return (from + 1);
	else
		return (-1);
}

t_move					get_movement(t_command dir)
{
	const t_move		movef[] =

	{
	[E_LEFTWARD] = walk_right,
	[E_RIGHTWARD] = walk_left,
	[E_UPWARD] = walk_down,
	[E_DOWNWARD] = walk_up
	};
	return (movef[dir]);
}
