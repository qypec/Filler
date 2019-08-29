/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:02:11 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/29 22:33:13 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_score				*init_score(void)
{
	t_score			*score;

	if ((score = (t_score *)malloc(sizeof(t_score))) == NULL)
		exit(-1);
	if ((score->coord = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		exit(-1);
	score->coord->x = 0;
	score->coord->y = 0;
	score->score = 0;
	return (score);
}

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
			if (g_map->field[y][x] == g_marker)
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
	int				overlay_player;
	int				overlay_rival;

	i = 0;
	overlay_player = 0;
	overlay_rival = 0;
	while (i < g_piece->height)
	{
		j = 0;
		while (j < g_piece->length)
		{
			if (g_piece->field[i][j] == '*' && \
					g_map->field[y + i][x + j] == g_marker)
				overlay_player++;
			if (g_piece->field[i][j] == '*' && \
				(g_map->field[y + i][x + j] == RIVALS_MARKER || \
				g_map->field[y + i][x + j] == RIVALS_MARKER - 32))
				return (0);
			j++;
		}
		i++;
	}
	if (overlay_player == 1)
		return (1);
	return (0);
}

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
	if (score < min_score->score)
	{
		min_score->score = score;
		min_score->coord->x = x;
		min_score->coord->y = y;
	}
}

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

void				put_piece(void)
{
	t_score			*min_score;

	min_score = init_score();
	min_score->coord->x = -1;
	min_score->coord->y = -1;
	min_score->score = g_map->height * g_map->length * 100;
	brute_force(min_score);
	ft_printf("%d %d\n", min_score->coord->y, min_score->coord->x);
}
