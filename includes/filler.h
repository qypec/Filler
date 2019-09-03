/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/03 14:12:17 by yquaro           ###   ########.fr       */
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

typedef	struct		s_rectangle
{
	t_coord			*left_apex;
	t_coord			*right_apex;
	int				free_space;
}					t_rectangle;

typedef struct		s_ghostly
{
	t_rectangle		*optimum;
	t_rectangle		*low;
	t_rectangle		*central;
}					t_ghostly;

typedef struct		s_score
{
	t_coord			*coord;
	int				score;
}					t_score;

t_ghostly			*g_rectangle;
t_token				*g_map;
t_token				*g_piece;
char				g_marker;

void				init_token(void);
void				tokendel(void);
void				init_ghostly_rectangles(void);
void				ghostly_rectangles_free(void);
t_score				*init_score(void);
void				score_del(t_score **min_score);

t_rectangle			*malloc_rectangle(void);

int					get_player_number(void);
int					map_parsing(void);
int					piece_parsing(void);

int					is_marker(char c, char marker);
void				fill_central_rectangles_coordinates(void);
void				choose_optimum_way(void);
int					make_a_move(void);

void				create_heat_map(void);
int					is_near_marker(int y, int x, char marker);
int					is_rectangle_zone(t_rectangle *rectangle, int y, int x);
int					is_near_border(int y, int x);

int					put_piece(void);

#endif
