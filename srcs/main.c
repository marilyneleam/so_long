/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:57:47 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 16:05:20 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_structure(t_all *all)
{
	all->map.pos_x = 0;
	all->map.pos_y = 0;
	all->map.step = 0;
	
}

int key_hook(int keycode, t_all *all)
{
	if (keycode == 119 && all->map.tab[all->map.pos_y - 1][all->map.pos_x] != '1')
	{
		all->map.pos_y -= 1;
		all->map.step++;
		ft_printf("Player move = %d\n", all->map.step);
	}
	if (keycode == 97 && all->map.tab[all->map.pos_y][all->map.pos_x - 1] != '1')
	{
		all->map.pos_x -= 1;
		all->map.step++;
		ft_printf("Player move = %d\n", all->map.step);
	}
	if (keycode == 115 && all->map.tab[all->map.pos_y + 1][all->map.pos_x] != '1')
	{
		all->map.pos_y += 1;
		all->map.step++;
		ft_printf("Player move = %d\n", all->map.step);
	}
	if (keycode == 100 && all->map.tab[all->map.pos_y][all->map.pos_x +1] != '1')
	{
		all->map.pos_x +=1;
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

int	main(int ac, char **av)
{
	t_all	all;

	init_structure(&all);
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
	mlx_hook(all.data.mlx_win, 2, 1L<<0, key_hook, &all);
	mlx_hook(all.data.mlx_win, 33, 1L<<2, mouse_close, &all);
	mlx_loop(all.data.mlx);
	return (0);
}
