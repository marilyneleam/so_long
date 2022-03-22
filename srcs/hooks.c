/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:23:19 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 17:53:31 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook_x(int keycode, t_all *all)
{
	if (keycode == 97 && all->map.tab[all->map.pos_y][all->map.pos_x - 1] != '1')
	{
		all->map.pos_x -= 1;
		return(1);
	}
	if (keycode == 100 && all->map.tab[all->map.pos_y][all->map.pos_x +1] != '1')
	{
		all->map.pos_x +=1;
		return (1);
	}
	return (0);
}

int key_hook_y(int keycode, t_all *all)
{
	if (keycode == 119 && all->map.tab[all->map.pos_y - 1][all->map.pos_x] != '1')
	{
		all->map.pos_y -= 1;
		return (1);
	}
	if (keycode == 115 && all->map.tab[all->map.pos_y + 1][all->map.pos_x] != '1')
	{
		all->map.pos_y += 1;
		return (1);
	}
	return (0);
}

int key_hook(int keycode, t_all *all)
{
	if(key_hook_x(keycode, all) == 1 || key_hook_y(keycode, all) == 1)
	{
		all->map.step++;
		ft_printf("Player move = %d\n", all->map.step);
	}
	if (keycode == 65307 || (all->map.tab[all->map.pos_y][all->map.pos_x] == 'E' && all->map.coll == 0))
	{
		ft_printf("Player total move = %d\n", all->map.step);
		mlx_destroy_window(all->data.mlx, all->data.mlx_win);
		exit(EXIT_SUCCESS);
	}
	draw_map(all);
	return (0);
}

int	mouse_close(t_all *all)
{
	ft_printf("Player total move = %d\n", all->map.step);
	mlx_destroy_window(all->data.mlx, all->data.mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}
