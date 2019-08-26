/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/26 20:42:32 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define IDENTIFY_MARKER(player_number) ((player_number == '1') ? 'O' : 'X')
# define RIVAL_MARKER(marker) ((marker == 'X') ? 'O' : 'X')

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

typedef	struct		s_square
{
	t_coord			*left_apex;
	t_coord			*right_apex;
	int				area;
}					t_square;

typedef struct		s_ghostly
{
	t_square		*optimum;
	t_square		*low;
	t_square		*central;
}					t_ghostly;

t_ghostly			*g_square;
t_token				*g_map;
t_token				*g_piece;
char				g_marker;
int					g_fd;

void				init_token(void);
void				tokendel(void);
void				init_ghostly_squares(void);
void				ghostly_squares_free(void);

void				get_central_square_coordinates(void);

void				get_player_number(void);
void				map_parsing(void);
void				piece_parsing(void);
int					make_a_move(void);

#endif