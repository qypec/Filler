/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:52:25 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/30 16:46:42 by yquaro           ###   ########.fr       */
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
	if (g_map == NULL)
		return ;
	ft_matrdel(&(g_map->field));
	g_map->field = NULL;
	g_map->height = 0;
	g_map->length = 0;
	free(g_map);
	g_map = NULL;
	if (g_piece == NULL)
		return ;
	ft_matrdel(&(g_piece->field));
	g_piece->field = NULL;
	g_piece->height = 0;
	g_piece->length = 0;
	free(g_piece);
	g_piece = NULL;
}

t_rectangle			*malloc_rectangle(void)
{
	t_rectangle		*rectangle;

	if ((rectangle = (t_rectangle *)malloc(sizeof(t_rectangle))) == NULL)
		return (NULL);
	if ((rectangle->left_apex = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		return (NULL);
	if ((rectangle->right_apex = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		return (NULL);
	rectangle->left_apex->x = 0;
	rectangle->left_apex->y = 0;
	rectangle->right_apex->x = 0;
	rectangle->right_apex->y = 0;
	rectangle->free_space = 0;
	return (rectangle);
}

void				init_ghostly_rectangles(void)
{
	if ((g_rectangle = (t_ghostly *)malloc(sizeof(t_ghostly))) == NULL)
		exit(-1);
	if ((g_rectangle->central = malloc_rectangle()) == NULL)
		exit(-1);
	g_rectangle->low = NULL;
	g_rectangle->optimum = NULL;
}

static void			rectangle_del(t_rectangle **rectangle)
{
	(*rectangle)->left_apex->x = 0;
	(*rectangle)->left_apex->y = 0;
	(*rectangle)->right_apex->x = 0;
	(*rectangle)->right_apex->y = 0;
	(*rectangle)->free_space = 0;
	free((*rectangle)->left_apex);
	(*rectangle)->left_apex = NULL;
	free((*rectangle)->right_apex);
	(*rectangle)->right_apex = NULL;
	free(*rectangle);
	rectangle = NULL;
}

void				ghostly_rectangles_free(void)
{
	rectangle_del(&(g_rectangle->optimum));
	g_rectangle->optimum = NULL;
	rectangle_del(&(g_rectangle->low));
	g_rectangle->low = NULL;
	rectangle_del(&(g_rectangle->central));
	g_rectangle->central = NULL;
	free(g_rectangle);
	g_rectangle = NULL;
}
