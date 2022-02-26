/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:57:47 by mleam             #+#    #+#             */
/*   Updated: 2022/02/26 17:42:19 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
