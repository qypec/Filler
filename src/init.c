/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:52:25 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/28 19:28:31 by yquaro           ###   ########.fr       */
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

t_square			*malloc_square(void)
{
	t_square		*square;

	if ((square = (t_square *)malloc(sizeof(t_square))) == NULL)
		return (NULL);
	if ((square->left_apex = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		return (NULL);
	if ((square->right_apex = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		return (NULL);
	square->left_apex->x = 0;
	square->left_apex->y = 0;
	square->right_apex->x = 0;
	square->right_apex->y = 0;
	square->area = 0;
	square->free_space = 0;
	return (square);
}

void				init_ghostly_squares(void)
{
	if ((g_square = (t_ghostly *)malloc(sizeof(t_ghostly))) == NULL)
		exit(-1);
	if ((g_square->central = malloc_square()) == NULL)
		exit(-1);
	g_square->low = NULL;
	g_square->optimum = NULL;
}

static void			square_del(t_square **square)
{
	(*square)->left_apex->x = 0;
	(*square)->left_apex->y = 0;
	(*square)->right_apex->x = 0;
	(*square)->right_apex->y = 0;
	(*square)->area = 0;
	(*square)->free_space = 0;
	free((*square)->left_apex);
	(*square)->left_apex = NULL;
	free((*square)->right_apex);
	(*square)->right_apex = NULL;
	free(*square);
	square = NULL;
}

void				ghostly_squares_free(void)
{
	square_del(&(g_square->optimum));
	g_square->optimum = NULL;
	square_del(&(g_square->low));
	g_square->low = NULL;
	square_del(&(g_square->central));
	g_square->central = NULL;
	free(g_square);
	g_square = NULL;
}
