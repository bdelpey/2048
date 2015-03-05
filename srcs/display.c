/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:52:22 by bdelpey           #+#    #+#             */
/*   Updated: 2015/03/05 17:42:46 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game_2048.h"
#include "libft.h"

static void			choose_color(int i)
{
	if (i == 2)
		attron(COLOR_PAIR(43));
	else if (i == 4)
		attron(COLOR_PAIR(44));
	else if (i == 8)
		attron(COLOR_PAIR(45));
	else if (i == 16)
		attron(COLOR_PAIR(46));
	else if (i == 32)
		attron(COLOR_PAIR(47));
	else if (i == 64)
		attron(COLOR_PAIR(48));
	else if (i == 128)
		attron(COLOR_PAIR(49));
	else if (i == 256)
		attron(COLOR_PAIR(50));
	else if (i == 512)
		attron(COLOR_PAIR(51));
	else if (i == 1024)
		attron(COLOR_PAIR(52));
	else if (i == 2048)
		attron(COLOR_PAIR(53));
	else
		attron(COLOR_PAIR(42));
}

static void			loop_two(t_tab *tab, int y, int k, int i)
{
	int				t;
	int				v;
	int				x;
	int				xm;
	int				l;

	x = 2 + (((COLS - 2 * tab->side - 2) / tab->side) + 2) * (i % tab->side);
	xm = x + ((COLS - 2 * tab->side - 2) / tab->side);
	l = xm;
	t = 0;
	v = 0;
	choose_color(tab->ar[i]);
	while (x < xm)
	{
		if ((y == k || y == k - 1) && (x == l || x == l - 1) && tab->ar[i])
		{
			v = y;
			t = x;
		}
		mvprintw(y, x, " ");
		x++;
		l--;
		if (x == xm && v && t)
			mvprintw(v, t, "%i", tab->ar[i]);
	}
}

static void			loop_one(t_tab *tab, int i)
{
	int				y;
	int				ym;
	int				k;

	y = 4 + (((LINES - 5 - tab->side) / tab->side) + 1) * (i / tab->side);
	ym = y + (LINES - 5 - tab->side) / tab->side;
	k = ym;
	while (y < ym)
	{
		loop_two(tab, y, k, i);
		y++;
		k--;
	}
}

static void			print_tile(t_tab *tab)
{
	int				i;

	i = 0;
	while (i < tab->side * tab->side)
	{
		loop_one(tab, i);
		i++;
	}
}

static void			print_background(t_tab *tab)
{
	int				y;
	int				x;
	int				ym;
	int				xm;

	y = 3;
	ym = (LINES - 5 - tab->side) / tab->side;
	xm = ((COLS - 2 * tab->side - 2) / tab->side);
	attron(COLOR_PAIR(54));
	while (y < (tab->side * ym + tab->side + 4))
	{
		x = 0;
		while (x < tab->side * xm + 2 * (tab->side + 1))
		{
			mvprintw(y, x, " ");
			x++;
		}
		y++;
	}
}

void				display(t_tab *tab)
{
	print_background(tab);
	print_tile(tab);
	return ;
}
