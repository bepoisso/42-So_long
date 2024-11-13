# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 15:52:46 by bepoisso          #+#    #+#              #
#    Updated: 2024/11/13 17:46:28 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_________________VARIABLE_________________

NAME = so_long.out

CC			= gcc
CFLAGS		= -Wall -Wextra -g #-Werror# 

MLX_NAME	= libmlx.a
MLX_FLAGS	= -l mlx -l Xext -l X11

#_________________DIRECTORY_________________
INC_DIR	= includes/
SRC_DIR	= srcs/
OBJ_DIR	= objs/
LIBFT_DIR	= ./libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a
MLX_DIR	= ./minilibx-linux/

#_________________FILES_________________

SRC_FILES	=\
	so_long.c\
	map_parser.c\
	movement.c\
	mlx_utiles.c\
	enemy.c\
	manip_lst.c
	
LIBSX		=	$(addprefix $(MLX_DIR),$(MLX_NAME))
SRCS		=	$(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR),$(SRC_FILES:.c=.o))

#_________________RULES_________________

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(LIBSX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(MLX_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

val:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./so_long.out

.PHONY: all clean fclean re
