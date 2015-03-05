/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:36:38 by bdelpey           #+#    #+#             */
/*   Updated: 2015/03/01 18:29:06 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_2048.h"

void					handle_sigwinch(int sig)
{
	extern t_tab		*g_tab;

	(void)sig;
	if (g_tab)
		refresh_display(g_tab);
	else
		ft_putendl_fd("Game table global pointer is NULL !", 2);
}
