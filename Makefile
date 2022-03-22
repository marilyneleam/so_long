# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleam <mleam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 16:37:46 by mleam             #+#    #+#              #
#    Updated: 2022/03/22 22:00:24 by mleam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom exécutable

NAME			=	so_long

# Commandes
CC				=	gcc
LINKER			=	gcc
RM				=	/bin/rm -rf # /bin/rm utilise le chemin de la commande au cas ou si alias sur zshrc
CREATE			= 	/bin/mkdir -p #p = si le dossier existe, il ne le refait pas


# Flags de compilations
CFLAGS			=	-Wall -Wextra -Werror -c #c permet de changer les points c en point o
CFLAGS			+=	-I includes #permet d'inclure le header au lieu du chemin du header
CFLAGS			+=	-MMD -MP -Imlx_linux #MMD MP permet de créer des dépendances
LFLAGS			+=	-lmlx -Lmlx_linux -lXext -lX11 -lm -L$(LIBFT_D) -lft -L$(FT_PRINTF_D) -lftprintf
#-lft correspond à -llibft.a
# -lftprint correspond à -llibftprintf.a
# -L permet de chercher dans le dossier des librairies
# -l permet de chercher la librairie

# Dossiers
LIBFT_D			=	libft/
FT_PRINTF_D		=	ft_printf/
SRCS_D			=	srcs/
GNL_D			=	gnl/
MLX_D			=	mlx_linux/
OBJS_D			=	objs/

# Librairies
LIBFT_N 		=	libft.a
LIBFT_N 		:=	$(addprefix $(LIBFT_D),$(LIBFT_N))
FT_PRINTF_N	 	=	libftprintf.a
FT_PRINTF_N 	:=	$(addprefix $(FT_PRINTF_D),$(FT_PRINTF_N))
MLX_N			=	libmlx.a
MLX_N 			:=	$(addprefix $(MLX_D),$(MLX_N))

# Fichiers sources
SRCS_SRCS		=	begin_mlx.c \
					check_all.c \
					check_file.c \
					check_map.c \
					check_map_param.c \
					check_texture.c \
					draw.c \
					free.c \
					hooks.c \
					init_images.c \
					init_structure.c \
					main.c \
					print_error.c \

SRCS_GNL		=	get_next_line.c \

SRCS_FT_PRINTF	=	ft_printf_adress.c \
					ft_printf.c \
					ft_printf_call.c \
					ft_printf_character_percent.c \
					ft_printf_decimal_integer.c \
					ft_printf_hexa_int_low.c \
					ft_printf_hexa_int_up.c \
					ft_printf_string.c \
					ft_printf_unsigned_integer.c \

# Fichiers objets
OBJS_SRCS		=	$(SRCS_SRCS:.c=.o)
OBJS_SRCS 		:=	$(addprefix $(OBJS_D), $(OBJS_SRCS))

OBJS_GNL		=	$(SRCS_GNL:.c=.o)
OBJS_GNL 		:=	$(addprefix $(OBJS_D), $(OBJS_GNL))

OBJS_FT_PRINTF	=	$(SRCS_FT_PRINTF:.c=.o)
OBJS_FT_PRINTF	:=	$(addprefix $(OBJS_D), $(OBJS_FT_PRINTF))

OBJS			=	$(OBJS_SRCS) $(OBJS_GNL) $(OBJS_FT_PRINTF)

# Dépendances
DEPS			=	$(OBJS:.o=.d)

# Règles
all:				$(NAME)

$(NAME):			$(OBJS) $(LIBFT_N) $(MLX_N) $(FT_PRINTF_N)
					$(LINKER) $(OBJS) $(LFLAGS) -o $@
# $@ correspond à tout = nom d'executable = so_long
# -o spécifie le fichier de sortie = so_long
# -c génère le fichier .o

-include $(DEPS)

$(OBJS_D)%.o:		$(SRCS_D)%.c
					$(CREATE) $(OBJS_D)
					$(CC) $(CFLAGS) -o $@ $<
					
$(OBJS_D)%.o:		$(GNL_D)%.c
					$(CREATE) $(OBJS_D)
					$(CC) $(CFLAGS) -o $@ $<

$(OBJS_D)%.o:		$(FT_PRINTF_D)%.c
					$(CREATE) $(OBJS_D)
					$(CC) $(CFLAGS) -o $@ $<

$(MLX_D)libmlx.a:	
					$(MAKE) -C $(MLX_D)

$(LIBFT_D)libft.a:	
					$(MAKE) -C $(LIBFT_D)

$(FT_PRINTF_D)libftprintf.a:	
					$(MAKE) -C $(FT_PRINTF_D)
					
clean:
					make clean -C $(LIBFT_D)
					make clean -C $(FT_PRINTF_D)
					make clean -C $(MLX_D)
					$(RM) $(OBJS_D)

fclean:				clean
					make fclean -C $(LIBFT_D)
					make fclean -C $(FT_PRINTF_D)
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
