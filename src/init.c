/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:52:25 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/24 18:13:46 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				init_token(void)
{
	if ((g_map = (t_token *)malloc(sizeof(t_token))) == NULL)
		exit(-1);
	g_map->field = NULL;
	g_map->height = 0;
	g_map->length = 0;
	if ((g_piece = (t_token *)malloc(sizeof(t_token))) == NULL)
		exit(-1);
	g_piece->field = NULL;
	g_piece->height = 0;
	g_piece->length = 0;
}

void				tokendel(void)
{
	ft_matrdel(&(g_map->field));
	g_map->field = NULL;
	g_map->height = 0;
	g_map->length = 0;
	free(g_map);
	g_map = NULL;
	ft_matrdel(&(g_piece->field));
	g_piece->field = NULL;
	g_piece->height = 0;
	g_piece->length = 0;
	free(g_piece);
	g_piece = NULL;
}