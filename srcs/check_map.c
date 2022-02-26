/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:00:16 by mleam             #+#    #+#             */
/*   Updated: 2022/02/26 16:01:04 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void	check_map_size(char **av, t_map *map)
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
		map->row++;
		free(line);
		line = NULL;
	}
	close(fd);
	if (map->row < 3)
		print_error(ERR_MAP_SMALL);
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
	map->tab = (char **)malloc(sizeof(char *) * (map->row + 1));
	if (!(map->tab))
		exit(EXIT_FAILURE);
	map->tab[map->row] = NULL;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		map->column = ft_strlen(line);
		map->tab[i++] = ft_strdup(line);
		free(line);
		line = NULL;
	}
	close(fd);
}

void	check_map_rectangle(t_map *map)
{
	int	i;
	int compare_len;

	i = 1;
	while(map->tab[i])
	{
		compare_len = ft_strlen(map->tab[i - 1]) - ft_strlen(map->tab[i]);
		if (compare_len != 0)
			print_error(ERR_MAP_RECTANGLE);
		i++;
	}
}

void	check_map_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while(map->tab[i])
	{
		j = 0;
		while(map->tab[i][j])
		{
			if (map->tab[0][j] != '1' || map->tab[i][0] != '1' || map->tab[map->row - 1][j] != '1' || map->tab[i][map->column -1] != '1')
				print_error(ERR_MAP_CLOSED);
			j++;
		}
		i++;
	}
}

