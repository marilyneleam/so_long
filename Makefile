# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleam <mleam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 23:05:54 by mleam             #+#    #+#              #
#    Updated: 2022/03/22 15:53:37 by mleam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT_D = libft
LIBFT_N = libft.a

FT_PRINTF_D =		ft_printf
FT_PRINTF_N =		libftprintf.a

SRCS	=	srcs/main.c \
			srcs/check_file.c \
			srcs/check_map.c \
			srcs/check_map_param.c \
			srcs/check_texture.c \
			srcs/print_error.c \
			srcs/init_images.c \
			srcs/draw.c \
			GNL/get_next_line.c \
			ft_printf/ft_printf_adress.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_printf_call.c \
			ft_printf/ft_printf_character_percent.c \
			ft_printf/ft_printf_decimal_integer.c \
			ft_printf/ft_printf_hexa_int_low.c \
			ft_printf/ft_printf_hexa_int_up.c \
			ft_printf/ft_printf_string.c \
			ft_printf/ft_printf_unsigned_integer.c \
			

OBJS	=	$(SRCS:.c=.o)

MLX_D	=	mlx_linux
LINUX	=	-I /usr/include -L /usr/lib/ -lmlx -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -I /usr/include -Imlx_mlx_linux -O3  -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT_D) $(FT_PRINTF_D)
				make -C $(LIBFT_D)
				cp $(LIBFT_D)/$(LIBFT_N) $(NAME)
				make -C $(FT_PRINTF_D)
				cp $(FT_PRINTF_D)/$(FT_PRINTF_N) $(NAME)
				ar -rcs $(NAME) $(OBJS)
		       	make -C	$(MLX_D) all
			$(CC) $(CFLAGS) $(OBJS) $(LINUX) $(LIBFT_D)/$(LIBFT_N) $(FT_PRINTF_D)/$(FT_PRINTF_N) -o $(NAME)

all:		$(NAME)

clean:
			make clean -C $(LIBFT_D)
			make clean -C $(FT_PRINTF_D)
			make clean -C $(MLX_D)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_D)
			make fclean -C $(FT_PRINTF_D)
			$(RM) $(NAME)
			make -C $(MLX_D) clean

re:			fclean all

.PHONY:		all clean fclean re
