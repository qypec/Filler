/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:28:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/02 17:00:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					main(void)
{
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
	g_marker = 0;
	return (0);
}
