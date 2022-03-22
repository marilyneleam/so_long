/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:59:03 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 22:19:50 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	begin_mlx(t_all *all)
{
	all->data.mlx = mlx_init();
	if (!all->data.mlx)
	{
		free_tab(all->map.tab);
		exit(EXIT_FAILURE);
	}	
}
