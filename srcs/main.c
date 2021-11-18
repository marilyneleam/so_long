/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:57:47 by mleam             #+#    #+#             */
/*   Updated: 2021/11/18 16:37:44 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        if (check_extension(av[1]) == -1)
            ft_putstr_fd("ERROR EXTENSION\n", 2);
    }
    else
        ft_putstr_fd("MISS OR TOO MUCH ARGS\n", 2);
    return (0);
}