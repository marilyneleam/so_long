/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:57:47 by mleam             #+#    #+#             */
/*   Updated: 2022/02/26 17:40:29 by mleam            ###   ########.fr       */
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
	if (all->map.tab[i][j] == 'C')
		mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->text.collectibles.img, j * 32, i * 32);
}

void	draw_map(t_all *all)
{
	int	i;
	int j;

	i = 0;
	while(all->map.tab[i])
	{
		j = 0;
		while(all->map.tab[i][j])
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

int	main(int ac, char **av)
{
	t_all	all;

	if (ac != 2)
		print_error(ERR_ARGS);
	check_and_read_file(av);
	check_extension(av[1]);
	check_map_size(av, &all.map);
	copy_map(av, &all.map);
	check_map_rectangle(&all.map);
	check_map_wall(&all.map);
	check_map_param(&all.map);
	check_texture();
	all.data.mlx = mlx_init();
	all.data.mlx_win = mlx_new_window(all.data.mlx, 32 * all.map.column, 32 * all.map.row, "./so_long");
	init_images(&all);
	draw_map(&all);
	mlx_loop(all.data.mlx);
	return (0);
}
