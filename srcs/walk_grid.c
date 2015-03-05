/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:37:41 by ffourati          #+#    #+#             */
/*   Updated: 2015/03/01 21:51:20 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int			try_merge(t_context *ctx, int from, t_command dir)
{
	int				changed;
	int				to;
	t_tab			*tab;

	changed = 0;
	to = from;
	tab = &ctx->tab;
	while ((to = get_movement(dir)(to, tab->side)) != -1)
	{
		if (tab->ar[to] == tab->ar[from])
		{
			tab->ar[from] <<= (tab->ar[to]) ? 1 : 0;
			tab->ar[to] = 0;
			changed |= 1;
			ctx->score += tab->ar[from];
			break ;
		}
		else if (tab->ar[to])
			break ;
	}
	return (changed);
}

static int			try_tilt(t_context *ctx, int from, t_command dir)
{
	int				changed;
	int				to;
	t_tab			*tab;

	changed = 0;
	to = from;
	tab = &ctx->tab;
	while ((to = get_movement(dir)(to, tab->side)) != -1)
	{
		if (tab->ar[to])
		{
			tab->ar[from] = tab->ar[to];
			tab->ar[to] = 0;
			changed |= 1;
			break ;
		}
		else if (tab->ar[to])
			break ;
	}
	return (changed);
}

static int			merge_duplicates(t_context *ctx, t_command dir)
{
	int				size;
	int				i;
	int				*sqar;
	int				changed;

	size = ctx->tab.side * ctx->tab.side;
	changed = 0;
	sqar = ctx->tab.ar;
	i = (dir < E_RIGHTWARD) ? 0 : size - 1;
	while (i < size && i >= 0)
	{
		if (sqar[i])
			changed |= try_merge(ctx, i, dir);
		i += (dir < E_RIGHTWARD) ? 1 : -1;
	}
	return (changed);
}

static int			tilt_array(t_context *ctx, t_command dir)
{
	int				size;
	int				i;
	int				*sqar;
	int				changed;

	size = ctx->tab.side * ctx->tab.side;
	changed = 0;
	sqar = ctx->tab.ar;
	i = (dir < E_RIGHTWARD) ? 0 : size - 1;
	while (i < size && i >= 0)
	{
		if (!sqar[i])
			changed |= try_tilt(ctx, i, dir);
		i += (dir < E_RIGHTWARD) ? 1 : -1;
	}
	return (changed);
}

int					walk_grid(t_context *ctx, t_command dir)
{
	int				changed;

	changed = 0;
	changed |= merge_duplicates(ctx, dir);
	changed |= tilt_array(ctx, dir);
	return (changed);
}
