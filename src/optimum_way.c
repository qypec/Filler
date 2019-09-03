/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimum_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:10:58 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/03 14:16:47 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			is_left_apex_above_right(void)
{
	if (g_rectangle->central->left_apex->y <= \
							g_rectangle->central->right_apex->y)
		return (1);
	return (0);
}

/*
** Defines the coordinates of artificially rectangles.
**
** @param	rectangle structures
** @return 	N/A
*/

static void			set_apex_coorinates(t_rectangle *rectangle1, \
											t_rectangle *rectangle2)
{
	rectangle1->left_apex->x = 0;
	rectangle1->left_apex->y = g_rectangle->central->left_apex->y;
	rectangle1->right_apex->x = g_rectangle->central->right_apex->x;
	rectangle2->right_apex->x = g_map->length - 1;
	rectangle2->right_apex->y = g_rectangle->central->right_apex->y;
	rectangle2->left_apex->x = g_rectangle->central->left_apex->x;
	if (is_left_apex_above_right())
	{
		rectangle1->right_apex->y = g_map->height - 1;
		rectangle2->left_apex->y = 0;
	}
	else
	{
		rectangle1->right_apex->y = 0;
		rectangle2->left_apex->y = g_map->height - 1;
	}
}

/*
** Counts the number of free cells in the selected rectangle.
**
** @param	rectangle structure
** @return 	N/A
*/

static void			get_rectangles_free_space(t_rectangle *rectangle)
{
	int				i;
	int				j;
	int				height;

	i = rectangle->right_apex->y;
	height = rectangle->left_apex->y;
	if (is_left_apex_above_right())
	{
		i = rectangle->left_apex->y;
		height = rectangle->right_apex->y;
	}
	while (i <= height)
	{
		j = rectangle->left_apex->x;
		while (j <= rectangle->right_apex->x)
		{
			if (g_map->field[i][j] == '.')
				(rectangle->free_space)++;
			j++;
		}
		i++;
	}
}

/*
** The central rectangle artificially extends to the borders
** of the map in two ways. The optimal path is the one in which
** the largest number of free cells.
**
** @param	N/A
** @return 	N/A
*/

void				choose_optimum_way(void)
{
	t_rectangle		*rectangle1;
	t_rectangle		*rectangle2;

	if ((rectangle1 = malloc_rectangle()) == NULL)
		exit(-1);
	if ((rectangle2 = malloc_rectangle()) == NULL)
		exit(-1);
	set_apex_coorinates(rectangle1, rectangle2);
	get_rectangles_free_space(rectangle1);
	get_rectangles_free_space(rectangle2);
	if (rectangle1->free_space >= rectangle2->free_space)
	{
		g_rectangle->optimum = rectangle1;
		g_rectangle->low = rectangle2;
	}
	else
	{
		g_rectangle->optimum = rectangle2;
		g_rectangle->low = rectangle1;
	}
}
