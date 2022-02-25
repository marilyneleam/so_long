/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:59:37 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 11:28:30 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int check_extension(char *str)
{
    int i;
    int j;
    char *ext_files;
    i = ft_strlen(str);
    j = i - 4;
    ext_files = &(str[j]);
    if (str[0] != '.' && ft_strcmp(ext_files, ".ber") == 0)
        return (1);
    return (-1);
}

int check_and_read(int ac, char **av)
{
    int fd;
    char *buf = NULL;
    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        printf("fd = %d\n", fd);
        if (fd == -1)
        {
            ft_putstr_fd("Error\n", 2);
            ft_putstr_fd(ERR_EXIST, 2);
            exit(EXIT_FAILURE);
        }
        if((read(fd, buf, 0) == -1))
        {
            ft_putstr_fd("Error\n", 2);
            ft_putstr_fd(ERR_DIRECTORY, 2);
            exit(EXIT_FAILURE);
        }
        close(fd);
    }
    return (1);
}