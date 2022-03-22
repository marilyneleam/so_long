/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:14:36 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 17:46:23 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_all(char **av, t_all *all)
{
	check_and_read_file(av);
	check_extension(av[1]);
	check_map_size(av, &all->map);
	copy_map(av, &all->map);
	check_map_rectangle(&all->map);
	check_map_wall(&all->map);
	check_map_param(&all->map);
	check_texture();
}