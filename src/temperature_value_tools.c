/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temperature_value_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:45:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/02 17:05:11 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					is_near_border(int y, int x)
{
	if (y == 0 || y == g_map->height - 1 || \
				x == 0 || x == g_map->length - 1)
		return (1);
	return (0);
}

int					is_square_zone(t_square *square, int y, int x)
{
	int				upper_apex;
	int				down_apex;

	if (square->left_apex->y <= square->right_apex->y)
	{
		upper_apex = square->left_apex->y;
		down_apex = square->right_apex->y;
	}
	else
	{
		upper_apex = square->right_apex->y;
		down_apex = square->left_apex->y;
	}
	if ((y >= upper_apex && y <= down_apex) && \
		(x >= square->left_apex->x && x <= square->right_apex->x))
		return (1);
	return (0);
}

static int			is_within_map(int changed_y, int changed_x)
{
	if ((changed_x >= 0 && changed_x <= g_map->length - 1) && \
		(changed_y >= 0 && changed_y <= g_map->height - 1))
		return (1);
	return (0);
}

int					is_near_marker(int y, int x, char marker)
{
	int				i;

	i = 0;
	while (++i < g_piece->height)
	{
		if (is_within_map(y + i, x - i) && \
				g_map->field[y + i][x - i] == marker)
			return (1);
		if (is_within_map(y + i, x) && \
				g_map->field[y + i][x] == marker)
			return (1);
		if (is_within_map(y + i, x + i) && \
				g_map->field[y + i][x + i] == marker)
			return (1);
		if (is_within_map(y, x + i) && \
				g_map->field[y][x + i] == marker)
			return (1);
		if (is_within_map(y - i, x + i) && \
				g_map->field[y - i][x + i] == marker)
			return (1);
		if (is_within_map(y - i, x) && \
				g_map->field[y - i][x] == marker)
			return (1);
		if (is_within_map(y - i, x - i) && \
				g_map->field[y - i][x - i] == marker)
			return (1);
		if (is_within_map(y, x - i) && \
				g_map->field[y][x - i] == marker)
			return (1);
	}
	return (0);
}
