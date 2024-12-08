# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 15:52:46 by bepoisso          #+#    #+#              #
#    Updated: 2024/12/08 13:09:18 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_________________VARIABLE_________________

NAME = so_long

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
	main.c\
	so_long_utiles.c\
	map_parser.c\
	map_parser_pt2.c\
	map_parser_pt3.c\
	movement.c\
	movement_pt2.c\
	mlx_utiles.c\
	mlx_destroy.c\
	scoreboard.c\
	scoreboard_pt2.c\
	scoreboard_pt3.c\
	teleporter.c\
	blinky_ai.c\
	pinky_ai.c\
	inky_ai.c\
	clyde_ai.c\
	init_img.c\
	init_img_pt2.c\
	help_utiles.c\
	print_entity.c\
	print_map.c\
	init_data.c\
	
LIBSX		=	$(addprefix $(MLX_DIR),$(MLX_NAME))
SRCS		=	$(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR),$(SRC_FILES:.c=.o))

#_________________RULES_________________

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(LIBSX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS) -lm

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

val: re
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./so_long test

debug: re
	gdb -tui -q $(NAME);

.PHONY: all clean fclean re val debug
