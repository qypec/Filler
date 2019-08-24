/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:28:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/24 18:20:38 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					main()
{
	get_player_number();
	while (1)
	{
		init_token();
		map_parsing();
		piece_parsing();
		if (make_a_move() == -1)
		{
			tokendel();
			break ;
		}
	}
	g_marker = 0;
	return (0);
}