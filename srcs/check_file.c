/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:59:37 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 16:40:14 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_extension(char *str)
{
	int		i;
	int		j;
	char	*ext_files;

	i = ft_strlen(str);
	j = i - 4;
	ext_files = &(str[j]);
	if (ft_strcmp(ext_files, ".ber") != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(ERR_EXTENSION, 2);
		exit(EXIT_FAILURE);
	}
	if (!str[j - 1] || str[j - 1] == '/')
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(ERR_NAME, 2);
		exit(EXIT_FAILURE);
	}
}

void	check_and_read_file(char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(ERR_EXIST, 2);
		exit(EXIT_FAILURE);
	}
	if ((read(fd, NULL, 0) == -1))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(ERR_DIRECTORY, 2);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
