/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:57:49 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 18:43:30 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_map_param(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	map->player = 0;
	map->coll = 0;
	map->exit = 0;
	while(map->tab[i])
	{
		j = 0;
		while(map->tab[i][j])
		{
			if (map->tab[i][j] != 'P' && map->tab[i][j] != 'E' && map->tab[i][j] != 'C' && map->tab[i][j] != '1' && map->tab[i][j] != '0')
				print_error(ERR_PARAM);
			if(map->tab[i][j] == 'P')
				map->player++;
			if(map->tab[i][j] == 'C')
				map->coll++;
			if(map->tab[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
}

void	check_map_param(t_map *map)
{
	count_map_param(map);
	if (map->player != 1)
		print_error(ERR_PARAM_PLAYER);
	if (map->coll == 0)
		print_error(ERR_PARAM_COLL);
	if (map->exit == 0)
		print_error(ERR_PARAM_EXIT);
}