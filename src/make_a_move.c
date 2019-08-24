/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 21:35:05 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/24 17:28:59 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord				*init_coord(void)
{
	t_coord			*coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	coord->x = 0;
	coord->y = 0;
	return (coord);
}

void				get_coordinates(t_coord *coord)
{
	int				i;
	int				j;

	i = 0;
	while (i < g_map->height)
	{
		j = 0;
		while (j < g_map->length)
		{
			if (g_map->field[i][j] == g_marker || g_map->field[i][j] == g_marker + 32)
			{
				coord->y = i;
				coord->x = j;
				break ;
			}
			j++;
		}
		if (coord->x != 0 && coord->y != 0)
			break ;
		i++;
	}
	if (coord->x - g_piece->length >= 0)
		coord->x -= (g_piece->length - 1);
	if (coord->y - g_piece->height >= 0)
		coord->y -= (g_piece->height - 1);
}

char				**fill_subpiece(t_coord *coord)
{
	char			**subpiece;
	int				i;
	int				j;

	subpiece = ft_matrsnew(g_piece->height, g_piece->length);
	i = 0;
	while (i < g_piece->height)
	{
		j = 0;
		while (j < g_piece->length)
		{
			subpiece[i][j] = g_map->field[coord->y + i][coord->x + j];
			j++;
		}
		i++;
	}
	// ft_printf("%w\n", subpiece);
	return (subpiece);
}

int					check_marker(char **subpiece)
{
	int				i;
	int				j;
	int				counter;

	counter = 0;
	i = 0;
	while (i < g_piece->height)
	{
		j = 0;
		while (j < g_piece->length)
		{
			if ((subpiece[i][j] == g_marker || subpiece[i][j] == g_marker + 32) \
				&& (g_piece->field[i][j] == '*'))
			{
				counter++;
			}
			j++;
		}
		i++;
	}
	if (counter == 1)
		return (1);
	return (0);
}

int					brute_force(t_coord *coord)
{
	char			**subpiece;

	subpiece = NULL;
	while (1)
	{
		ft_matrdel(&subpiece);
		subpiece = fill_subpiece(coord);
		if (check_marker(subpiece) == 1)
		{
			ft_printf("%d %d\n", coord->y, coord->x);
			return (1);
		}
		if (coord->x + 1 + g_piece->length > g_map->length)
			break ;
		coord->x += 1;
	}
	return (-1);
}

int					make_a_move(void)
{
	t_coord			*coord;

	coord = init_coord();
	get_coordinates(coord);
	if (brute_force(coord) == -1)
		return (-1);
	return (1);
	// ft_printf("%d %d\n", 12, 12);
}
