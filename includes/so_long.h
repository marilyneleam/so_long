/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:28:14 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 11:11:30 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "msg_error.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void check_error(int ac, char **av);
int check_extension(char *str);
int check_and_read(int ac, char **av);
int main(int ac, char **av);
