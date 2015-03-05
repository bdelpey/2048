/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:23:09 by bdelpey           #+#    #+#             */
/*   Updated: 2015/03/05 18:09:23 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"
#include "game_2048.h"

t_tab				*g_tab = NULL;

static void			init_colors(void)
{
	init_pair(42, COLOR_BLACK, 102);
	init_pair(43, COLOR_BLACK, 231);			//2
	init_pair(44, COLOR_BLACK, 7);				//4
	init_pair(45, COLOR_BLACK, 180);			//8
	init_pair(46, COLOR_BLACK, 173);			//16
	init_pair(47, COLOR_BLACK, 167);			//32
	init_pair(48, COLOR_BLACK, 124);			//64
	init_pair(49, COLOR_BLACK, 228);			//128
	init_pair(50, COLOR_BLACK, 227);			//256
	init_pair(51, COLOR_BLACK, 226);			//512
	init_pair(52, COLOR_BLACK, 172);			//1024
	init_pair(53, COLOR_BLACK, 33);				//2048
	init_pair(54, COLOR_BLACK, 241);
}

static void			init_curse(void)
{
	srand(time(NULL));
	initscr();
	curs_set(0);
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	use_default_colors();
	init_colors();
}

static int			init_context(t_context *ctx, char *arg)
{
	t_tab			*tab;
	int				size;

	tab = &ctx->tab;
	if (!arg || ft_strcmp(arg, "--4x4") == 0)
		tab->side = SIDE_4;
	else if (ft_strcmp(arg, "--5x5") == 0)
		tab->side = SIDE_5;
	else
		return (1);
	size = tab->side * tab->side;
	if ((tab->ar = (int *)malloc(sizeof(int) * size)) == NULL
			|| (ctx->room_map = (int *)malloc(sizeof(int) * size)) == NULL)
		return (-1);
	return (0);
}

static void			setup_signals(void)
{
	signal(SIGWINCH, &handle_sigwinch);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
}

int					main(int ac, char **av)
{
	t_context		ctx;
	t_game_status	status;
	int				err;

	if ((err = !(ac == 1 || ac == 2)) || (err |= init_context(&ctx, av[1])))
	{
		if (err == 1)
			ft_putnstr_fd(2, 3, "Usage: ", av[0], " [--4x4 | --5x5]\n");
		return (err);
	}
	g_tab = &ctx.tab;
	setup_signals();
	init_curse();
	status = core(&ctx);
	err = (status == E_STATUS_FATAL);
	refresh();
	clear();
	endwin();
	free(ctx.room_map);
	free(ctx.tab.ar);
	return (err);
}
