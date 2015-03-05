/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infer_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:06:15 by ffourati          #+#    #+#             */
/*   Updated: 2015/03/01 21:24:05 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_2048.h"

static void				analyze_tab(t_context *sandbox, int *max, int *free,
						int *can_move)
{
	const int			length = sandbox->tab.side * sandbox->tab.side;
	const int			*tab = sandbox->tab.ar;
	int					i;

	*max = 0;
	*free = 0;
	*can_move = 0;
	i = 0;
	while (i < length)
	{
		if (tab[i] > *max)
			*max = tab[i];
		if (tab[i] == 0)
			++(*free);
		++i;
	}
	i = E_LEFTWARD;
	while (i <= E_DOWNWARD)
		*can_move |= walk_grid(sandbox, i++);
}

static t_game_status	deduct_status(int max, int free, int can_move)
{
	(void)free;
	if (!can_move)
		return (E_STATUS_LOST);
	else if (max < WIN_VALUE)
		return (E_STATUS_OK);
	else if (max < MAX_VALUE)
		return (E_STATUS_WON);
	else if (max >= MAX_VALUE)
		return (E_STATUS_MAXED);
	else
		return (E_STATUS_FATAL);
}

t_game_status			infer_status(t_context *ctx)
{
	int					max;
	int					free;
	int					can_move;
	t_context			sandbox;

	ft_memcpy(ctx->room_map, ctx->tab.ar
			, sizeof(int) * (ctx->tab.side * ctx->tab.side));
	sandbox.tab.ar = ctx->room_map;
	sandbox.tab.side = ctx->tab.side;
	analyze_tab(&sandbox, &max, &free, &can_move);
	return (deduct_status(max, free, can_move));
}
