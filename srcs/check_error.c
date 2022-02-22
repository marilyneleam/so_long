/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:58:53 by mleam             #+#    #+#             */
/*   Updated: 2022/02/19 15:42:12 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_error(int ac, char **av)
{
    if (ac == 2)
    {
        if (check_extension(av[1]) == -1)
        {
            ft_putstr("Error\n");
            ft_putstr(ERR_EXTENSION);
        }
    }
    else
    {
        ft_putstr("Error\n");
        ft_putstr(ERR_ARGS);
    }
}