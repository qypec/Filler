/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:28:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/30 17:54:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					is_marker(char c, char marker)
{
	if (c == marker || c == marker + 32)
		return (1);
	return (0);
}

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
	g_map = NULL;
	g_piece = NULL;
	if (get_player_number() == -1)
		return (0);
	while (1)
	{
		init_token();
		if (map_parsing() == -1)
			break ;
		if (piece_parsing() == -1)
			break ;
		if (make_a_move() == -1)
			break ;
		tokendel();
	}
	tokendel();
	// g_marker = 0;

	// int i;
	// int	j;

	// i = 0;
	// while (g_map->field[i] != NULL)
	// {
	// 	j = 0;
	// 	while (j < g_map->length)
	// 	{
	// 		if (g_map->field[i][j] == 'O' || g_map->field[i][j] == 'X' || \
	// 			g_map->field[i][j] == '.' || g_map->field[i][j] == 'o' || \
	// 			g_map->field[i][j] == 'x')
	// 		{
	// 			ft_printf("%3c", g_map->field[i][j]);
	// 		}
	// 		else
	// 		{
	// 			ft_printf("%3d", (int)g_map->field[i][j]);
	// 		}
	// 		j++;
	// 	}
	// 	write(1, "\n", 1);
	// 	i++;
	// }
	// close(g_fd);
	return (0);
}