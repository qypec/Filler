/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/28 19:28:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define IDENTIFY_MARKER(player_number) ((player_number == '1') ? 'O' : 'X')
# define RIVAL_MARKER(marker) ((marker == 'X') ? 'O' : 'X')
# define LEFT_APEX_ABOVE_RIGHT ((g_square->central->right_apex->y <= \
								g_square->central->left_apex->y) ? 0 : 1)

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
	int				free_space;
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

t_square			*malloc_square(void);

void				fill_central_squares_coordinates(void);
void				choose_optimum_way(void);

void				get_player_number(void);
void				map_parsing(void);
void				piece_parsing(void);
int					make_a_move(void);

#endif