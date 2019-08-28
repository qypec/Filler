/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 21:35:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/28 19:41:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					make_a_move(void)
{
	init_ghostly_squares();
	fill_central_squares_coordinates();
	choose_optimum_way();

	return (1);
}



	// ft_printf("field:\n%w\n\n", g_map->field);

	// printf("central:\n");
	// printf("left apex:\nx = %d\ny = %d\n", g_square->central->left_apex->x, \
	// 										g_square->central->left_apex->y);
	// printf("right apex:\nx = %d\ny = %d\n", g_square->central->right_apex->x, \
	// 										g_square->central->right_apex->y);
	// printf("area = %d\n", g_square->central->area);

	// printf("optimum:\n");
	// printf("left apex:\nx = %d\ny = %d\n", g_square->optimum->left_apex->x, \
	// 										g_square->optimum->left_apex->y);
	// printf("right apex:\nx = %d\ny = %d\n", g_square->optimum->right_apex->x, \
	// 										g_square->optimum->right_apex->y);
	// printf("area = %d\n", g_square->optimum->area);
	// printf("free_space = %d\n", g_square->optimum->free_space);

	// printf("\nlow:\n");
	// printf("left apex:\nx = %d\ny = %d\n", g_square->low->left_apex->x, \
	// 										g_square->low->left_apex->y);
	// printf("right apex:\nx = %d\ny = %d\n", g_square->low->right_apex->x, \
	// 										g_square->low->right_apex->y);
	// printf("area = %d\n", g_square->low->area);
	// printf("free_space = %d\n", g_square->low->free_space);