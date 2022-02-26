/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:57:47 by mleam             #+#    #+#             */
/*   Updated: 2022/02/26 16:28:40 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;

	if (ac != 2)
		print_error(ERR_ARGS);
	check_and_read_file(av);
	check_extension(av[1]);
	check_map_size(av, &map);
	copy_map(av, &map);
	check_map_rectangle(&map);
	check_map_wall(&map);
	check_map_param(&map);
	check_texture();
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 32 * map.column, 32 * map.row, "./so_long");
	mlx_loop(data.mlx);
	return (0);
}
