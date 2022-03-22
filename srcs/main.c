/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:57:47 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 18:02:00 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int ac, char **av)
{
	t_all	all;

	init_structure(&all);
	if (ac != 2)
		print_error(ERR_ARGS);
	check_all(av, &all);
	all.data.mlx = mlx_init();
	all.data.mlx_win = mlx_new_window(all.data.mlx, 32 * all.map.column, 32 * all.map.row, "./so_long");
	init_images(&all);
	draw_map(&all);
	mlx_hook(all.data.mlx_win, 2, 1L<<0, key_hook, &all);
	mlx_hook(all.data.mlx_win, 33, 1L<<2, mouse_close, &all);
	mlx_loop(all.data.mlx);
	free_tab(all.map.tab);
	return (0);
}
