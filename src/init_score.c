/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:02:47 by yquaro            #+#    #+#             */
/*   Updated: 2019/09/02 17:03:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_score				*init_score(void)
{
	t_score			*score;

	if ((score = (t_score *)malloc(sizeof(t_score))) == NULL)
		exit(-1);
	if ((score->coord = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		exit(-1);
	score->coord->x = 0;
	score->coord->y = 0;
	score->score = 0;
	return (score);
}

void				score_del(t_score **min_score)
{
	(*min_score)->coord->x = 0;
	(*min_score)->coord->y = 0;
	free((*min_score)->coord);
	(*min_score)->coord = NULL;
	(*min_score)->score = 0;
	free(*min_score);
	min_score = NULL;
}
