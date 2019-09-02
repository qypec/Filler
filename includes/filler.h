/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/02 17:03:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define IDENTIFY_MARKER(player_number) ((player_number == '1') ? 'O' : 'X')
# define RIVALS_MARKER ((g_marker == 'X') ? 'O' : 'X')

# define START_DISTANCE 3

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

typedef struct		s_score
{
	t_coord			*coord;
	int				score;
}					t_score;

t_ghostly			*g_square;
t_token				*g_map;
t_token				*g_piece;
char				g_marker;
int					g_fd;

int					is_marker(char c, char marker);

void				init_token(void);
void				tokendel(void);
void				init_ghostly_squares(void);
void				ghostly_squares_free(void);
t_score				*init_score(void);
void				score_del(t_score **min_score);

t_square			*malloc_square(void);

int					get_rivals_center(char coordinate_axis);
void				fill_central_squares_coordinates(void);
void				choose_optimum_way(void);

int					get_player_number(void);
int					map_parsing(void);
int					piece_parsing(void);
int					make_a_move(void);

void				create_heat_map(void);
int					is_near_marker(int y, int x, char marker);
int					is_square_zone(t_square *square, int y, int x);
int					is_near_border(int y, int x);

int					put_piece(void);

#endif
