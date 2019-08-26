/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:28:37 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/26 20:42:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					main()
{
	g_fd = open("test", O_RDONLY);

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
	close(g_fd);
	return (0);
}