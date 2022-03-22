/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:45:12 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 22:30:23 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_texture_extension(char *str)
{
	int		i;
	int		j;
	char	*ext_files;

	i = ft_strlen(str);
	j = i - 4;
	ext_files = &(str[j]);
	if (ft_strcmp(ext_files, ".xpm") != 0)
		print_error(ERR_EXTENSION);
	if (!str[j - 1] || str[j - 1] == '/')
		print_error(ERR_NAME);
}

void	check_and_read_texture(char *pathfile)
{
	int		fd;

	fd = open(pathfile, O_RDONLY);
	if (fd == -1)
		print_error(ERR_EXIST);
	if ((read(fd, NULL, 0) == -1))
		print_error(ERR_DIRECTORY);
	close(fd);
}

void	check_texture(void)
{
	check_texture_extension(PLAYER);
	check_texture_extension(COLLECTIBLES);
	check_texture_extension(EXIT);
	check_texture_extension(WALL);
	check_texture_extension(GROUND);
}
