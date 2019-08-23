/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:52:25 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/23 20:45:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_token				*init_token(void)
{
	t_token			*token;

	if ((token = (t_token *)malloc(sizeof(t_token))) == NULL)
		exit(-1);
	token->field = NULL;
	token->height = 0;
	token->length = 0;
	return (token);
}