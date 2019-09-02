/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 21:35:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/02 17:46:09 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** If the character is equal to the marker in upper or lower case, 
** then returns 1, otherwise 0.
*/

int					is_marker(char c, char marker)
{
	if (c == marker || c == marker + 32)
		return (1);
	return (0);
}

/*
** Returns the coordinate of the opponent’s center according 
** to the given coordinate axis.
*/

int					get_rivals_center(char coordinate_axis)
{
	int				y;
	int				x;

	y = g_square->central->left_apex->y;
	x = g_square->central->left_apex->x;
	if (is_marker(g_map->field[y][x], RIVALS_MARKER))
		return ((coordinate_axis == 'x') ? x : y);
	return ((coordinate_axis == 'x') ? \
		g_square->central->right_apex->x : g_square->central->right_apex->y);
}

/*
** Make a move.
**
** @return return_code	Returns the signal to complete the loop 
**						if there is nowhere else to put the figure.
*/

int					make_a_move(void)
{
	int				return_code;

	init_ghostly_squares();
	fill_central_squares_coordinates();
	choose_optimum_way();
	create_heat_map();
	return_code = put_piece();
	ghostly_squares_free();
	return (return_code);
}
