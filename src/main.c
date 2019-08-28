/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:28:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/28 23:35:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					get_rivals_center(char coordinate_axis)
{
	int				y;
	int				x;

	y = g_square->central->left_apex->y;
	x = g_square->central->left_apex->x;
	if (g_map->field[y][x] == RIVALS_MARKER)
		return ((coordinate_axis == 'x') ? x : y);
	return ((coordinate_axis == 'x') ? \
		g_square->central->right_apex->x : g_square->central->right_apex->y);
}

int					main()
{
	// g_fd = open("test", O_RDONLY);

	// get_player_number();
	// // while (1)
	// // {
	// 	init_token();
	// 	map_parsing();
	// 	piece_parsing();
	// 	if (make_a_move() == -1)
	// 	{
	// 		tokendel();
	// 		// break ;
	// 	}
	// // }
	// g_marker = 0;
	// close(g_fd);
	char c;

	c = -1;
	printf("c = %c\n d = %d\n", c, (int)c);
	return (0);
}