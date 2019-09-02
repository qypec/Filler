/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 17:26:26 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/02 17:22:22 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Parses the size of a map or piece.
**
** @param	N/A
** @return	-1  if get_next_line returned an error
*/

static void			get_field_size(const char *line, t_token *token)
{
	const char		*field_size;
	t_buff			*num;
	int				i;

	field_size = ft_strchr(line, ' ') + 1;
	num = ft_buffinit(10);
	i = 0;
	while (ft_isdigit(field_size[i]) && field_size[i] != '\0')
		ft_buffaddsymb(num, field_size[i++]);
	token->height = ft_atoi(num->str);
	ft_buffdel(&num);
	num = ft_buffinit(10);
	i++;
	while (ft_isdigit(field_size[i]) && field_size[i] != '\0')
		ft_buffaddsymb(num, field_size[i++]);
	token->length = ft_atoi(num->str);
	ft_buffdel(&num);
}

/*
** Parses the map.
**
** @param	N/A
** @return	-1  if get_next_line returned an error
*/

int					map_parsing(void)
{
	char			*line;
	int				i;
	const char		*field_line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (-1);
	get_field_size(line, g_map);
	if ((g_map->field = (char **)ft_matrmemalloc(sizeof(char *) * \
									(g_map->height + 1))) == NULL)
		exit(-1);
	if (get_next_line(0, &line) <= 0)
		return (-1);
	i = 0;
	while (i < g_map->height)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		field_line = ft_strchr(line, ' ') + 1;
		g_map->field[i++] = ft_strdup(field_line);
	}
	ft_strdel(&line);
	return (1);
}

/*
** Parses the figure that the player needs to put on the map.
**
** @param	N/A
** @return	-1  if get_next_line returned an error
*/

int					piece_parsing(void)
{
	char			*line;
	int				i;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
	{
		ft_strdel(&line);
		return (-1);
	}
	get_field_size(line, g_piece);
	if ((g_piece->field = (char **)ft_matrmemalloc(sizeof(char *) * \
									(g_piece->height + 1))) == NULL)
		exit(-1);
	i = 0;
	while (i < g_piece->height)
	{
		if (get_next_line(0, &line) <= 0)
		{
			ft_strdel(&line);
			return (-1);
		}
		g_piece->field[i++] = ft_strdup(line);
	}
	ft_strdel(&line);
	return (1);
}

/*
** Parses the first line received from the virtual machine 
** to determine the player’s marker.
**
** @param	N/A
** @return	-1  if get_next_line returned an error
*/

int					get_player_number(void)
{
	char			symb;
	char			*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
	{
		ft_strdel(&line);
		return (-1);
	}
	symb = *(ft_strchr(line, 'p') + 1);
	g_marker = IDENTIFY_MARKER(symb);
	ft_strdel(&line);
	return (1);
}
