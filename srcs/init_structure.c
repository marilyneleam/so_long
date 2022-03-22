/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:09:49 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 22:44:36 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_structure(t_all *all)
{
	all->map.row = 0;
	all->map.column = 0;
	all->map.tab = NULL;
	all->map.exit = 0;
	all->map.coll = 0;
	all->map.player = 0;
	all->map.pos_x = 0;
	all->map.pos_y = 0;
	all->map.step = 0;
}
