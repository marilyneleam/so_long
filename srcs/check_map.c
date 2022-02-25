/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:00:16 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 16:32:56 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void	check_validity_map(char **av, t_map *map)
{
	int		fd;
	int		ret;
	char	*line;

	map->row = 0;
	ret = 1;
	fd = open(av[1], O_RDONLY);
	line = NULL;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == 1)
			map->row++;
		free(line);
		line = NULL;
	}
	close(fd);
	if (map->row < 3)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(ERR_MAP_SMALL, 2);
		exit(EXIT_FAILURE);
	}
}

void	copy_map(char **av, t_map *map)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	ret = 1;
	map->column = 0;
	map->tab = (char **)malloc(sizeof(char *) * map->row + 1);
	if (!(map->tab))
		exit(EXIT_FAILURE);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			map->column = ft_strlen(line);
			map->tab[i++] = ft_strdup(line);
		}
		free(line);
		line = NULL;
	}
	close(fd);
}
