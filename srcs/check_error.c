/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:58:53 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 10:57:25 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_error(int ac, char **av)
{
    if (ac == 2)
    {
        if (check_extension(av[1]) == -1)
        {
            ft_putstr_fd("Error\n", 2);
            ft_putstr_fd(ERR_EXTENSION, 2);
        }
    }
    else
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd(ERR_ARGS, 2);
    }
}