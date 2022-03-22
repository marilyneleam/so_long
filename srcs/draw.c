/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:42:33 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 14:54:33 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	pos_player(t_all *all, int i, int j)
{
	if(all->map.tab[i][j] == 'P')
	{
		all->map.pos_x = j;
		all->map.pos_y = i;
		all->map.tab[i][j] = '0';
	}
}

void	draw_elements(t_all *all, int i, int j)
{
	if (all->map.tab[i][j] == '1')
		mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->text.wall.img, j * 32, i * 32);
	if (all->map.tab[i][j] == '0')
		mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->text.ground.img, j * 32, i * 32);
	if (all->map.tab[i][j] == 'E')
		mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->text.exit.img, j * 32, i * 32);
}

void	draw_collectibles(t_all *all, int i, int j)
{
	if(all->map.tab[all->map.pos_y][all->map.pos_x] == 'C')
		all->map.tab[all->map.pos_y][all->map.pos_x] = '0';
	if (all->map.tab[i][j] == 'C')
		mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->text.collectibles.img, j * 32, i * 32);
}

void	draw_map(t_all *all)
{
	int	i;
	int j;

	i = 0;
	while(i < all->map.row)
	{
		j = 0;
		while(j < all->map.column)
		{
			pos_player(all, i, j);
			draw_elements(all, i , j);
			draw_collectibles(all, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->text.player.img, all->map.pos_x * 32, all->map.pos_y * 32);
}