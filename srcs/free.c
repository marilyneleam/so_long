/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:43:50 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 21:54:53 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while(tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_and_exit(t_all *all)
{
	free_tab(all->map.tab);
	ft_printf("Player total move = %d\n", all->map.step);
	mlx_destroy_window(all->data.mlx, all->data.mlx_win);
	mlx_destroy_image(all->data.mlx, all->text.player.img);
	mlx_destroy_image(all->data.mlx, all->text.wall.img);
	mlx_destroy_image(all->data.mlx, all->text.ground.img);
	mlx_destroy_image(all->data.mlx, all->text.collectibles.img);
	mlx_destroy_image(all->data.mlx, all->text.exit.img);
	mlx_destroy_display(all->data.mlx);
	free(all->data.mlx);
	exit(EXIT_SUCCESS);
}