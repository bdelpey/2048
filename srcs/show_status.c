/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:40:25 by ffourati          #+#    #+#             */
/*   Updated: 2015/03/01 21:36:04 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game_2048.h"

void					show_status(t_context *ctx, t_game_status status)
{
	const char			*const statuses[] =

	{
	[E_STATUS_OK] = "",
	[E_STATUS_WON] = "You won ! Press Esc to quit or F5 start over.",
	[E_STATUS_MAXED] = "You made the best tile ! Esc: Quit  F5: Restart",
	[E_STATUS_LOST] = "You Lost. Press Esc to quit or F5 start over.",
	[E_STATUS_FATAL] = "Something went terribly wrong. Press Esc to quit."
	};
	mvprintw(1, 1, "Score: %i", ctx->score);
	mvprintw(2, 1, "%s", statuses[status]);
}
