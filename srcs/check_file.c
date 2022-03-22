/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:59:37 by mleam             #+#    #+#             */
/*   Updated: 2022/03/22 17:46:23 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *str)
{
	int		i;
	int		j;
	char	*ext_files;

	i = ft_strlen(str);
	j = i - 4;
	ext_files = &(str[j]);
	if (ft_strcmp(ext_files, ".ber") != 0)
		print_error(ERR_EXTENSION);
	if (!str[j - 1] || str[j - 1] == '/')
		print_error(ERR_NAME);
}

void	check_and_read_file(char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error(ERR_EXIST);
	if ((read(fd, NULL, 0) == -1))
		print_error(ERR_DIRECTORY);
	close(fd);
}
