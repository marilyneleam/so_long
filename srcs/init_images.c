/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:45 by mleam             #+#    #+#             */
/*   Updated: 2022/02/26 17:12:45 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	init_image(t_all *all, char *pathfile)
{
	t_img img;
	img.img = mlx_xpm_file_to_image(all->data.mlx, pathfile, &img.width, &img.height);
	if (!img.img)
		exit(EXIT_FAILURE);	
	return (img);
}

void	init_images(t_all *all)
{
	all->text.wall = init_image(all, WALL);
	all->text.ground = init_image(all, GROUND);
	all->text.collectibles = init_image(all, COLLECTIBLES);
	all->text.player = init_image(all, PLAYER);
	all->text.exit = init_image(all, EXIT);
}