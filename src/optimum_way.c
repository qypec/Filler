/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimum_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:10:58 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/02 15:27:23 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			is_left_apex_above_right(void)
{
	if (g_square->central->left_apex->y <= g_square->central->right_apex->y)
		return (1);
	return (0);
}

static void			set_apex_coorinates(t_square *square1, t_square *square2)
{
	square1->left_apex->x = 0;
	square1->left_apex->y = g_square->central->left_apex->y;
	square1->right_apex->x = g_square->central->right_apex->x;
	square2->right_apex->x = g_map->length - 1;
	square2->right_apex->y = g_square->central->right_apex->y;
	square2->left_apex->x = g_square->central->left_apex->x;
	if (is_left_apex_above_right())
	{
		square1->right_apex->y = g_map->height - 1;
		square2->left_apex->y = 0;
	}
	else
	{
		square1->right_apex->y = 0;
		square2->left_apex->y = g_map->height - 1;
	}
}

void				get_squares_free_space(t_square *square)
{
	int				i;
	int				j;
	int				height;

	i = square->right_apex->y;
	height = square->left_apex->y;
	if (is_left_apex_above_right())
	{
		i = square->left_apex->y;
		height = square->right_apex->y;
	}
	while (i <= height)
	{
		j = square->left_apex->x;
		while (j <= square->right_apex->x)
		{
			if (g_map->field[i][j] == '.')
				(square->free_space)++;
			j++;
		}
		i++;
	}
}

void				choose_optimum_way(void)
{
	t_square		*square1;
	t_square		*square2;

	if ((square1 = malloc_square()) == NULL)
		exit(-1);
	if ((square2 = malloc_square()) == NULL)
		exit(-1);
	set_apex_coorinates(square1, square2);
	get_squares_free_space(square1);
	get_squares_free_space(square2);
	if (square1->free_space >= square2->free_space)
	{
		g_square->optimum = square1;
		g_square->low = square2;
	}
	else
	{
		g_square->optimum = square2;
		g_square->low = square1;
	}
}
