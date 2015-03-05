/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:10:21 by ffourati          #+#    #+#             */
/*   Updated: 2015/03/01 22:28:18 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_2048.h"

static int						new_game(t_context *ctx, t_command cmd)
{
	(void)cmd;
	ft_bzero(ctx->tab.ar, sizeof(int) * ctx->tab.side * ctx->tab.side);
	ctx->score = 0;
	insert(ctx);
	insert(ctx);
	return (0);
}

static int						noop(t_context *ctx, t_command cmd)
{
	(void)cmd;
	(void)ctx;
	return (0);
}

t_routine						get_routine(t_command cmd)
{
	const t_routine				routines[] =

	{
	[E_LEFTWARD] = &walk_grid,
	[E_UPWARD] = &walk_grid,
	[E_RIGHTWARD] = &walk_grid,
	[E_DOWNWARD] = &walk_grid,
	[E_NEWGAME] = &new_game,
	[E_UNKNOWN] = &noop,
	[E_QUIT] = &noop
	};
	return (routines[cmd]);
}
