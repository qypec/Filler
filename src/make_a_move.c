/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 21:35:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/03 11:37:50 by yquaro           ###   ########.fr       */
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
** Make a move.
**
** @return return_code	Returns the signal to complete the loop 
**						if there is nowhere else to put the figure.
*/

int					make_a_move(void)
{
	int				return_code;

	init_ghostly_rectangles();
	fill_central_rectangles_coordinates();
	choose_optimum_way();
	create_heat_map();
	return_code = put_piece();
	ghostly_rectangles_free();
	return (return_code);
}
