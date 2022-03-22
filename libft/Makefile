# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleam <mleam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 23:29:18 by mleam             #+#    #+#              #
#    Updated: 2022/03/22 15:35:42 by mleam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_itoa_base.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strrev.c \
			ft_ultoa_base.c \

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re