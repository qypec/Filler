/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:11:26 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/03 12:01:28 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Returns the coordinate of the opponent’s center according 
** to the given coordinate axis.
*/

static int			get_rivals_center(char coordinate_axis)
{
	int				y;
	int				x;

	y = g_rectangle->central->left_apex->y;
	x = g_rectangle->central->left_apex->x;
	if (is_marker(g_map->field[y][x], RIVALS_MARKER))
		return ((coordinate_axis == 'x') ? x : y);
	y = g_rectangle->central->right_apex->y;
	x = g_rectangle->central->right_apex->x;
	return ((coordinate_axis == 'x') ? x : y);
}

/*
** Defines the final coordinate for the current fill layer.
**
** @param	coordinate_axis		the coordinate to be determined
** @param	distance			indent from the enemy`s center
** @return	final coordinate
*/

static int			get_final_distance_coordinate(char coordinate_axis, \
													int distance)
{
	int				coord;
	int				borders_coordinate;

	borders_coordinate = 0;
	coord = get_rivals_center(coordinate_axis) + ROUND_DOWN(distance / 2);
	if (coordinate_axis == 'x')
		borders_coordinate = g_map->length - 1;
	else if (coordinate_axis == 'y')
		borders_coordinate = g_map->height - 1;
	if (coord > borders_coordinate)
		return (borders_coordinate);
	return (coord);
}

/*
** Defines the start coordinate for the current fill layer.
**
** @param	coordinate_axis		the coordinate to be determined
** @param	distance			indent from the enemy`s center
** @return	start coordinate
*/

static int			get_start_distance_coordinate(char coordinate_axis, \
													int distance)
{
	int				coord;

	coord = get_rivals_center(coordinate_axis) - ROUND_DOWN(distance / 2);
	if (coord < 0)
		return (0);
	return (coord);
}

/*
** Calculates the temperature value for a specific map cell.
**
** @param	distance_counter		indent from the enemy`s center
** @return	temperature_counter		temperature value
*/

static int			get_temperature_value(int y, int x, \
										int distance_counter)
{
	int				temperature_counter;

	if (g_map->field[y][x] != '.')
		return (g_map->field[y][x]);
	temperature_counter = distance_counter;
	if (is_rectangle_zone(g_rectangle->central, y, x))
		temperature_counter -= 2;
	if (is_rectangle_zone(g_rectangle->low, y, x))
		temperature_counter += 2;
	if (is_rectangle_zone(g_rectangle->optimum, y, x))
		temperature_counter -= 2;
	if (is_near_border(y, x))
		temperature_counter -= 4;
	if (is_near_marker(y, x, RIVALS_MARKER))
		temperature_counter -= 5;
	return (temperature_counter);
}

/*
** Fills a specific map layer around the enemy’s 
** center with temperature values.
**
** @param	start_x		x-position which layer begins
** @param	start_y		y-position which layer begins
** @param	final_x		x-position which layer ends
** @param	final_y		y-position which layer ends
** @param	distance_counter	indent from the enemy`s center
*/

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
