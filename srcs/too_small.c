/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   too_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 20:06:45 by bdelpey           #+#    #+#             */
/*   Updated: 2015/03/01 19:13:01 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

int				too_small(int side)
{
	endwin();
	refresh();
	clear();
	if (COLS < (8 * side + 1) || LINES < (4 * side + 4))
	{
		mvprintw(0, 0, "Too small !");
		refresh();
		return (1);
	}
	return (0);
}
