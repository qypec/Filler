/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 17:26:26 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/23 19:09:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			get_player_number(void)
{
	char			symb;
	char			*line;

/**/int fd;
/**/fd = open("src/test", O_RDONLY);
	get_next_line(fd, &line);
	symb = *(ft_strchr(line, 'p') + 1);
	g_marker = GET_MARKER(symb);
/**/close(fd);
}

// static void			get_plateau(void)
// {
	
// }

void				read_plateau_and_piece(void)
{
	get_player_number();
}