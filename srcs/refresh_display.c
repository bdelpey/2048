/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:25:31 by ffourati          #+#    #+#             */
/*   Updated: 2015/03/01 18:28:27 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game_2048.h"

void					refresh_display(t_tab *tab)
{
	if (too_small(tab->side))
		return ;
	display(tab);
	refresh();
}
