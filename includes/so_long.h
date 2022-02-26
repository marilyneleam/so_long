/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:28:14 by mleam             #+#    #+#             */
/*   Updated: 2022/02/26 17:32:47 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "msg_error.h"
# include "../GNL/get_next_line.h"
# include "../mlx_linux/mlx.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PLAYER "./textures/player.xpm"
# define COLLECTIBLES "./textures/heart.xpm"
# define EXIT "./textures/exit.xpm"
# define WALL "./textures/tree.xpm"
# define GROUND "./textures/ground.xpm"

typedef struct s_map
{
	int		row;
	int		column;
	char	**tab;
	int		exit;
	int		coll;
	int		player;
	int		pos_x;
	int		pos_y;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}				t_data;

typedef struct	s_img
{
	void	*img;
	int		height;
	int		width;
}				t_img;

typedef struct	s_text
{
	t_img	wall;
	t_img	ground;
	t_img	player;
	t_img	collectibles;
	t_img	exit;
}				t_text;

typedef struct	s_all
{
	t_map	map;
	t_data	data;
	t_img	img;
	t_text	text;
}				t_all;


void	check_extension(char *str);
void	check_and_read_file(char **av);
void	check_map_size(char **av, t_map *map);
void	copy_map(char **av, t_map *map);
void	check_map_rectangle(t_map *map);
void	check_map_wall(t_map *map);
void	count_map_param(t_map *map);
void	check_map_param(t_map *map);
void	print_error(char *s);
void	check_texture_extension(char *str);
void	check_and_read_texture(char *pathfile);
void	check_texture();
t_img	init_image(t_all *all, char *pathfile);
void	init_images(t_all *all);
int		main(int ac, char **av);

#endif
