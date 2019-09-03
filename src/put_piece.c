/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:02:11 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/03 13:27:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					get_start_coordinate(void)
{
	int				y;
	int				x;

	y = 0;
	while (y < g_map->height)
	{
		x = 0;
		while (x < g_map->length)
		{
			if (is_marker(g_map->field[y][x], g_marker))
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int					is_correct_location(int y, int x)
{
	int				i;
	int				j;
	int				overlay_dot;
	int				overlay_player;

	overlay_dot = 0;
	overlay_player = 0;
	i = -1;
	while (++i < g_piece->height)
	{
		j = -1;
		while (++j < g_piece->length)
		{
			if (g_piece->field[i][j] == '*' && \
					!is_marker(g_map->field[y + i][x + j], g_marker))
				overlay_dot++;
			if (g_piece->field[i][j] == '*' && \
					is_marker(g_map->field[y + i][x + j], g_marker))
				overlay_player++;
			if (g_piece->field[i][j] == '*' && \
					is_marker(g_map->field[y + i][x + j], RIVALS_MARKER))
				return (0);
		}
	}
	if (overlay_dot > 0 && overlay_player > 0)
		return (1);
	return (0);
}

/*
** Counts the sum of thermal values and overwrites
** the score structure if the score is the smallest.
**
** @param	x, y	current position
*/

void				update_min_score(t_score *min_score, int y, int x)
{
	int				i;
	int				j;
	int				score;

	score = 0;
	i = 0;
	while (i < g_piece->height)
	{
		j = 0;
		while (j < g_piece->length)
		{
			if (g_piece->field[i][j] == '*')
				score += (int)(g_map->field[y + i][x + j]);
			j++;
		}
		i++;
	}
	if (score <= min_score->score)
	{
		min_score->score = score;
		min_score->coord->x = x;
		min_score->coord->y = y;
	}
}

/*
** Enumeration of possible locations of a piece.
** Search for the smallest sum of thermal 
** values covered by a piece.
*/

void				brute_force(t_score *min_score)
{
	int				y;
	int				x;

	if ((y = get_start_coordinate() - g_piece->height + 1) < 0)
		y = 0;
	while ((y + g_piece->height - 1) < g_map->height)
	{
		x = 0;
		while ((x + g_piece->length - 1) < g_map->length)
		{
			if (is_correct_location(y, x))
				update_min_score(min_score, y, x);
			x++;
		}
		y++;
	}
}

/*
** Finds the optimal position to insert a piece.
** Writes the result to standard output.
*/

int					put_piece(void)
{
	t_score			*min_score;
	int				y;
	int				x;

	min_score = init_score();
	min_score->coord->x = -1;
	min_score->coord->y = -1;
	min_score->score = g_map->height * g_map->length * 100;
	brute_force(min_score);
	y = min_score->coord->y;
	x = min_score->coord->x;
	score_del(&min_score);
	ft_printf("%d %d\n", y, x);
	if (y == -1 || x == -1)
		return (-1);
	return (1);
}
