/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 20:19:50 by bdelpey           #+#    #+#             */
/*   Updated: 2015/03/01 20:09:24 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_2048.h"

void					insert(t_context *ctx)
{
	int					k;
	int					max;
	int					count;

	count = 0;
	max = 0;
	k = 0;
	while (k < ctx->tab.side * ctx->tab.side)
	{
		max = (max < ctx->tab.ar[k]) ? ctx->tab.ar[k] : max;
		if (ctx->tab.ar[k] == 0)
		{
			ctx->room_map[count] = k;
			++count;
		}
		++k;
	}
	if (count == 0)
		return ;
	k = rand() % count;
	ctx->tab.ar[ctx->room_map[k]] = (rand() % 100 < CHANCE_OF_FOUR) ? 4 : 2;
}
