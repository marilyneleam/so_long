/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:28:14 by mleam             #+#    #+#             */
/*   Updated: 2022/02/25 16:29:16 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "msg_error.h"
# include "../GNL/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	int		row;
	int		column;
	char	**tab;
}				t_map;

void	check_extension(char *str);
void	check_and_read_file(char **av);
void	check_validity_map(char **av, t_map *map);
void	copy_map(char **av, t_map *map);
int		main(int ac, char **av);

#endif
