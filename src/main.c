/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:28:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/24 16:35:22 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main()
{
	get_player_number();
	while (1)
	{
		g_map = init_token();
		g_piece = init_token();
		input_parsing();
		if (make_a_move() == -1)
			break ;
		tokendel(&g_map);
		tokendel(&g_piece);
	}
	tokendel(&g_map);
	tokendel(&g_piece);
}