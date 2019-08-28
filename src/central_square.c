/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:31:18 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/28 22:19:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			get_square_area(void)
{
	int				height;
	int				length;

	height = g_square->central->right_apex->y - g_square->central->left_apex->y;
	length = g_square->central->right_apex->x - g_square->central->left_apex->x;
	return ((ft_abs(height) + 1) * (ft_abs(length) + 1));
}

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
			if (g_map->field[i][j] == marker)
				shape_size++;
		}
	}
	return (shape_size);
}

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
			if (g_map->field[i][j] == marker)
				sum_y += i;
		}
	}
	return (sum_y);
}

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
			if (g_map->field[i][j] == marker)
				sum_x += j;
		}
	}
	return (sum_x);
}

void				fill_central_squares_coordinates(void)
{
	int				rival_sum_x;
	int				player_sum_x;

	rival_sum_x = get_xsum(RIVALS_MARKER) / \
							get_shape_size(RIVALS_MARKER);
	player_sum_x = get_xsum(g_marker) / get_shape_size(g_marker);
	if (rival_sum_x <= player_sum_x)
	{
		g_square->central->left_apex->x = rival_sum_x;
		g_square->central->left_apex->y = (get_ysum(RIVALS_MARKER) / \
							get_shape_size(RIVALS_MARKER));
		g_square->central->right_apex->x = player_sum_x;
		g_square->central->right_apex->y = (get_ysum(g_marker) / \
							get_shape_size(g_marker));
	}
	else
	{
		g_square->central->left_apex->x = player_sum_x;
		g_square->central->left_apex->y = (get_ysum(g_marker) / \
							get_shape_size(g_marker));
		g_square->central->right_apex->x = rival_sum_x;
		g_square->central->right_apex->y = (get_ysum(RIVALS_MARKER) / \
							get_shape_size(RIVALS_MARKER));
	}
	g_square->central->area = get_square_area();
}
