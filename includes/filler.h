/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/24 18:21:01 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define IDENTIFY_MARKER(player_number) ((player_number == '1') ? 'O' : 'X')

typedef struct		s_token
{
	char			**field;
	int				height;
	int				length;
}					t_token;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

t_token				*g_map;
t_token				*g_piece;
char				g_marker;

void				init_token(void);
void				tokendel(void);

void				get_player_number(void);
void				map_parsing(void);
void				piece_parsing(void);
int					make_a_move(void);

#endif