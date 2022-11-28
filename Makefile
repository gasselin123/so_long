# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 11:49:55 by gasselin          #+#    #+#              #
#    Updated: 2022/11/28 09:03:16 by gasselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRC			=	srcs
INC			=	includes
OBJ			=	objs

LIB			=	lib
LIBFT		=	$(LIB)/libft
MLX_LINUX	=	$(LIB)/mlx_linux
MLX_MAC 	= 	$(LIB)/mlx_mac

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g

YELLOW 	= \033[0;33m
GREEN 	= \033[0;32m
RED 	= \033[0;31m
END 	= \033[0m

RM			=	rm -rf
MK			=	mkdir -p
NM			=	norminette

MAKE_DIR	= $(MAKE) -C

CFILES		=	so_long.c \
						ft_is_map_valid.c \
						ft_manage_timer.c \
						ft_move.c \
						ft_print_map.c \
						ft_utils.c \
						ft_utils2.c \
						move_enemy.c \

HFILES		=	so_long.h
				
OFILES		 =	$(CFILES:.c=.o)

SRCS			=	$(addprefix $(SRC)/, $(CFILES))
HEADERS			=	$(addprefix $(INC)/, $(HFILES))
OBJS			=	$(addprefix $(OBJ)/, $(OFILES))

VPATH		=	$(SRCS)

FRAMEWORKS_MAC 		= -lft -lmlx -lm -framework OpenGL -framework AppKit
FRAMEWORKS_LINUX 	= -lft -lmlx -lm -lXext -lbsd -lX11

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -I$(INC) -I$(LIB) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJS)
		@echo "$(GREEN) Compiling..."
		@$(MAKE_DIR) $(LIBFT)
		@$(MAKE_DIR) $(MLX_MAC)
		$(CC) $(OBJS) -L$(LIBFT) -L$(MLX_MAC) $(FRAMEWORKS_MAC) -o $(NAME)
		@echo "$(END)"
		@echo "$(GREEN)  So Long Compiled\n $(END)"

$(OBJ):
			@$(MK) $(OBJ)

linux:		$(OBJ) $(OBJS)
			@echo "$(GREEN) Compiling..."
			@$(MAKE_DIR) $(LIBFT)
			@$(MAKE_DIR) $(MLX_LINUX)
			$(CC) $(OBJS)  -L$(LIBFT) -L$(MLX_LINUX) $(FRAMEWORKS_LINUX) -o $(NAME)
			@echo "$(GREEN) Cub3D Compiled\n $(END)"
			
clean:
			@$(MAKE_DIR) $(LIBFT) clean
			@$(MAKE_DIR) $(MLX_MAC) clean
			@$(RM) $(OBJS)
			@$(RM) $(OBJ)

linux-clean:
			@echo "$(RED) Cleaning..."
			@$(MAKE_DIR) $(LIBFT) clean
			@$(MAKE_DIR) $(MLX_LINUX) clean
			@$(RM) $(OBJS)
			@$(RM) $(OBJ)
			@echo "$(END)"

fclean:		clean
			@echo "$(RED) Removing executable..."
			@$(MAKE_DIR) $(LIBFT) fclean
			@$(RM) $(NAME)
			@echo "$(END)"

re:			fclean all

relinux:			fclean linux

norm:
			@$(NM) $(SRCS) $(HEADERS)

val: all
	valgrind   --leak-check=full --track-origins=yes -s --trace-children=yes  ./$(NAME) map.cub

.PHONY:		all debug clean fclean re linux