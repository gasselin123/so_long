# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 11:49:55 by gasselin          #+#    #+#              #
#    Updated: 2021/07/15 14:35:20 by gasselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
MYLIB		= mylib.a

RM			= rm -rf
CC			= gcc
FLAGS		= -g -Wall -Wextra -Werror 
FLAGSMX		= -lmlx -framework OpenGL -framework AppKit
INCS		= .

SRCS		= so_long.c \
				ft_is_map_valid.c \
				ft_print_map.c \
				ft_move.c \
				ft_utils.c \
				ft_utils2.c \
				move_enemy.c \
				ft_manage_timer.c

OBJS		= ${SRCS:.c=.o}

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJS}
			$(MAKE) bonus -C ./ft_printf
			ar -rcs ${MYLIB} ${OBJS}
			${CC} ${FLAGS} ${MYLIB} ${FLAGSMX} -o ${NAME} ft_printf/libftprintf.a

all : ${NAME}

clean :
			$(MAKE) clean -C ./ft_printf
			${RM} ${OBJS}

fclean : clean
			$(MAKE) fclean -C ./ft_printf
			${RM} ${MYLIB}
			${RM} ${NAME}

re : fclean all