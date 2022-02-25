# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleam <mleam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 23:05:54 by mleam             #+#    #+#              #
#    Updated: 2022/02/25 18:47:27 by mleam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT_D = libft
LIBFT_N = libft.a

SRCS	=	srcs/main.c \
			srcs/check_file.c \
			srcs/check_map.c \
			srcs/check_map_param.c \
			srcs/check_texture.c \
			srcs/print_error.c \
			GNL/get_next_line.c \

OBJS	=	$(SRCS:.c=.o)

MLX_D	=	mlx_linux
LINUX	=	-I /usr/include -L /usr/lib/ -lmlx -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -I /usr/include -Imlx_mlx_linux -O3  -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT_D)
				make -C $(LIBFT_D)
				cp $(LIBFT_D)/$(LIBFT_N) $(NAME)
				ar -rcs $(NAME) $(OBJS)
		       	make -C	$(MLX_D) all
			$(CC) $(CFLAGS) $(OBJS) $(LINUX) $(LIBFT_D)/$(LIBFT_N) -o $(NAME)

all:		$(NAME)

clean:
			make clean -C $(LIBFT_D)
			make clean -C $(MLX_D)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_D)
			$(RM) $(NAME)
			make -C $(MLX_D) clean

re:			fclean all

.PHONY:		all clean fclean re
