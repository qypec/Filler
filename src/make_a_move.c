/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 21:35:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/26 20:44:45 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					make_a_move(void)
{
	init_ghostly_squares();
	get_central_square_coordinates();
	
}



	// printf("left apex:\nx = %d\ny = %d\n", g_square->central->left_apex->x, \
	// 										g_square->central->left_apex->y);
	// printf("right apex:\nx = %d\ny = %d\n", g_square->central->right_apex->x, \
	// 										g_square->central->right_apex->y);
	// printf("area = %d\n", g_square->central->area);