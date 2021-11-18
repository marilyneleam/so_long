/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:59:37 by mleam             #+#    #+#             */
/*   Updated: 2021/11/18 16:37:21 by mleam            ###   ########.fr       */
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