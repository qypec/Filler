/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_rectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:31:18 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/03 11:39:44 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Counts the number of cells
**
** @param	marker	player`s marker
** @return 	shape_size	number of cells
*/

static int			get_shape_size(char marker)
{
	int				i;
	int				j;
	int				shape_size;

	shape_size = 0;
	i = -1;
	while (++i < g_map->height)
	{
		j = -1;
		while (++j < g_map->length)
		{
			if (is_marker(g_map->field[i][j], marker))
				shape_size++;
		}
	}
	return (shape_size);
}

/*
** Counts the sum of y-coordinate of a specific player.
**
** @param	marker	player`s marker
** @return 	sum_y
*/

static int			get_ysum(char marker)
{
	int				i;
	int				j;
	int				sum_y;

	sum_y = 0;
	i = -1;
	while (++i < g_map->height)
	{
		j = -1;
		while (++j < g_map->length)
		{
			if (is_marker(g_map->field[i][j], marker))
				sum_y += i;
		}
	}
	return (sum_y);
}

/*
** Counts the sum of x-coordinate of a specific player.
**
** @param	marker	player`s marker
** @return 	sum_x
*/

static int			get_xsum(char marker)
{
	int				i;
	int				j;
	int				sum_x;

	sum_x = 0;
	i = -1;
	while (++i < g_map->height)
	{
		j = -1;
		while (++j < g_map->length)
		{
			if (is_marker(g_map->field[i][j], marker))
				sum_x += j;
		}
	}
	return (sum_x);
}

/*
** Counts the center of the opponent’s and player’s figures, 
** writes this to the appropriate structure.
**
** @param N/A
** @return N/A
*/

void				fill_central_rectangles_coordinates(void)
{
	int				rival_sum_x;
	int				player_sum_x;

	rival_sum_x = get_xsum(RIVALS_MARKER) / get_shape_size(RIVALS_MARKER);
	player_sum_x = get_xsum(g_marker) / get_shape_size(g_marker);
	if (rival_sum_x <= player_sum_x)
	{
		g_rectangle->central->left_apex->x = rival_sum_x;
		g_rectangle->central->left_apex->y = \
				(get_ysum(RIVALS_MARKER) / get_shape_size(RIVALS_MARKER));
		g_rectangle->central->right_apex->x = player_sum_x;
		g_rectangle->central->right_apex->y = \
				(get_ysum(g_marker) / get_shape_size(g_marker));
	}
	else
	{
		g_rectangle->central->left_apex->x = player_sum_x;
		g_rectangle->central->left_apex->y = \
				(get_ysum(g_marker) / get_shape_size(g_marker));
		g_rectangle->central->right_apex->x = rival_sum_x;
		g_rectangle->central->right_apex->y = \
				(get_ysum(RIVALS_MARKER) / get_shape_size(RIVALS_MARKER));
	}
}
