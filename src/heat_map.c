/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:11:26 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/29 17:48:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			get_final_distance_coordinate(char coordinate_axis, \
													int distance)
{
	int				coord;
	int				borders_coordinate;

	coord = get_rivals_center(coordinate_axis) + ROUND_DOWN(distance / 2);
	if (coordinate_axis == 'x')
		borders_coordinate = g_map->length - 1;
	else if (coordinate_axis == 'y')
		borders_coordinate = g_map->height - 1;
	if (coord > borders_coordinate)
		return (borders_coordinate);
	return (coord);

}

static int			get_start_distance_coordinate(char coordinate_axis, \
													int distance)
{
	int				coord;

	coord = get_rivals_center(coordinate_axis) - ROUND_DOWN(distance / 2);
	if (coord < 0)
		return (0);
	return (coord);
}

static int			get_temperature_value(int y, int x, \
										int distance_counter)
{
	int				temperature_counter;

	if (g_map->field[y][x] != '.')
		return (g_map->field[y][x]);
	temperature_counter = distance_counter;
	temperature_counter -= is_square_zone(g_square->central, y, x);
	temperature_counter += is_square_zone(g_square->low, y, x);
	temperature_counter -= is_square_zone(g_square->optimum, y, x);
	// temperature_counter -= is_above_red_line(y, x);
	temperature_counter -= IS_NEAR_MAPS_BORDER(y, x);
	temperature_counter -= is_near_players_marker(y, x);
	return (temperature_counter);
}

static void			fill_heat_map_layer(int start_x, int start_y, \
										int final_x, int final_y, \
										int distance_counter)
{
	int				x;
	int				y;

	y = start_y;
	while (y <= final_y)
	{
		x = start_x;
		while (x <= final_x)
		{
			g_map->field[y][x] = get_temperature_value(y, x, \
											distance_counter);
			x++;
		}
		y++;
	}
}

void				create_heat_map(void)
{
	int				distance;
	int				start_x;
	int				start_y;
	int				final_x;
	int				final_y;

	distance = START_DISTANCE;
	while (distance <= (g_map->length * 2) || distance <= (g_map->height * 2))
	{
		start_x = get_start_distance_coordinate('x', distance);
		start_y = get_start_distance_coordinate('y', distance);
		final_x = get_final_distance_coordinate('x', distance);
		final_y = get_final_distance_coordinate('y', distance);
		fill_heat_map_layer(start_x, start_y, final_x, final_y, \
								ROUND_DOWN(distance / 2));
		distance += 2;
	}
}
