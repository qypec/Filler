/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 17:26:26 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/23 17:49:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			get_player_number(void)
{
	char			symb;
	char			previous_symb;
	int				ret;

	previous_symb = 0;
/**/int fd;
/**/fd = open("src/test", O_RDONLY);
	while ((ret = read(fd, &symb, 1)) > 0 && previous_symb != 'p')
		previous_symb = symb;
	if (ret == -1 || ret == 0)
		exit(-1);
	g_marker = GET_MARKER(symb);
/**/close(fd);
}

static void			get_plateau(void)
{
	
}

void				read_plateau_and_piece(void)
{
	get_player_number();
	get_plateau();
}