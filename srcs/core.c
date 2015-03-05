/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:40:27 by ffourati          #+#    #+#             */
/*   Updated: 2015/03/01 22:29:22 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game_2048.h"

static t_command				get_command(t_game_status status)
{
	int							key;

	key = getch();
	if (key == '\033')
		return (E_QUIT);
	else if (key == KEY_F(5) && status != E_STATUS_FATAL)
		return (E_NEWGAME);
	else if (key == KEY_UP && status <= E_STATUS_WON)
		return (E_UPWARD);
	else if (key == KEY_DOWN && status <= E_STATUS_WON)
		return (E_DOWNWARD);
	else if (key == KEY_LEFT && status <= E_STATUS_WON)
		return (E_LEFTWARD);
	else if (key == KEY_RIGHT && status <= E_STATUS_WON)
		return (E_RIGHTWARD);
	else
		return (E_UNKNOWN);
}

static void						init_game(t_context *ctx)
{
	get_routine(E_NEWGAME)(ctx, E_UNKNOWN);
	if (!too_small(ctx->tab.side))
	{
		display(&ctx->tab);
		show_status(ctx, E_STATUS_OK);
	}
}

t_game_status					core(t_context *ctx)
{
	t_game_status				status;
	t_command					cmd;
	int							result;

	status = E_STATUS_OK;
	cmd = E_UNKNOWN;
	init_game(ctx);
	while ((cmd = get_command(status)) < E_QUIT && status <= E_STATUS_FATAL)
	{
		flushinp();
		if (!too_small(ctx->tab.side))
		{
			result = get_routine(cmd)(ctx, cmd);
			if (cmd != E_QUIT && cmd != E_UNKNOWN
					&& (cmd <= E_DOWNWARD && result != 0))
				insert(ctx);
			display(&ctx->tab);
			show_status(ctx, (status = infer_status(ctx)));
		}
	}
	return (status);
}
