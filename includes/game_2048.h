/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:34:38 by ffourati          #+#    #+#             */
/*   Updated: 2015/03/01 22:23:19 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# define SIDE_4 (4)
# define SIDE_5 (5)
# define CHANCE_OF_FOUR (20)

typedef struct				s_tab
{
	int						*ar;
	int						side;
}							t_tab;

typedef struct				s_context
{
	struct s_tab			tab;
	int						*room_map;
	int						score;
}							t_context;

/*
** 2^11 == 2048
** 2^14 == 16384
*/

enum						e_const
{
	WIN_VALUE = (1 << 11),
	MAX_VALUE = (1 << 14)
};

/*
** enum value order DOES matter / ! \
*/

typedef enum				e_game_status
{
	E_STATUS_OK = 0,
	E_STATUS_WON,
	E_STATUS_MAXED,
	E_STATUS_LOST,
	E_STATUS_FATAL
}							t_game_status;

/*
** enum value order DOES matter / ! \
*/

typedef enum				e_command
{
	E_LEFTWARD = 0,
	E_UPWARD,
	E_RIGHTWARD,
	E_DOWNWARD,
	E_NEWGAME,
	E_UNKNOWN,
	E_QUIT
}							t_command;

typedef int					(*t_move)(int, int);
typedef int					(*t_routine)(t_context *, t_command);

void						handle_command(t_command cmd);
t_move						get_movement(t_command dir);
int							walk_grid(t_context *ctx, t_command dir);
void						handle_sigwinch(int sig);
void						refresh_display(t_tab *tab);
void						display(t_tab *tab);
int							too_small(int side);
void						insert(t_context *ctx);
t_game_status				core(t_context *ctx);
t_game_status				infer_status(t_context *ctx);
void						show_status(t_context *ctx, t_game_status status);
t_routine					get_routine(t_command cmd);

#endif
