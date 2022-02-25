/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:57:47 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 16:40:56 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(ERR_ARGS, 2);
		return (-1);
	}
	check_and_read_file(av);
	check_extension(av[1]);
	check_validity_map(av, &map);
	copy_map(av, &map);
	return (0);
}
