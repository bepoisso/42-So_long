/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:10:42 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/28 16:02:08 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//_________________MACROS_________________
# define TEXTUR_SIZE 32
// # define TESTER ft_printf("\ntester\n");
# define BLINKY 'W'
# define PINKY 'X'
# define INKY 'Y'
# define CLYDE 'Z'
# define PLAYER 'P'

//_________________INCLUDES_________________
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>

//_________________STRUCT&ENUM_________________
// Struct for drawing in the mlx window
typedef struct s_mlx_draw
{
	int	x_start;
	int	y_start;
	int	size_x;
	int	size_y;
	int	radius;
	int	thickness;
	int	color;
}	t_mlx_draw;

// Struct to manage the image in the mlx window
typedef struct s_mlx_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
	void	*img_down;
	char	*path_down;
	void	*img_left;
	char	*path_left;
	void	*img_right;
	char	*path_right;
}	t_mlx_img;

// struct of struct of all my image set
typedef struct s_mlx_all_img
{
	t_mlx_img	character_left;
	t_mlx_img	character_right;
	t_mlx_img	character_up;
	t_mlx_img	character_down;
	t_mlx_img	character1;
	t_mlx_img	item;
	t_mlx_img	floor;
	t_mlx_img	wall;
	t_mlx_img	exit;
	t_mlx_img	exit1;
	t_mlx_img	blinky;
	t_mlx_img	pinky;
	t_mlx_img	inky;
	t_mlx_img	clyde;
	t_mlx_img	help;
	int			x;
	int			y;
}	t_mlx_all_img;

// struct to manage the map
typedef struct s_mlx_map
{
	char	**map;
	char	**temp_map;
	int		x;
	int		y;
	int		x_max;
	int		y_max;
	int		item;
	int		move_count;
	char	stach;
	int		last_move;
}	t_mlx_map;

// Struct for player
typedef struct s_player
{
	int		x;
	int		y;
	int		move_count;
	int		last_move;
	int		img_frame;
}	t_player;

// Struct for blinky
typedef struct s_blinky
{
	char	stash;
	int		x;
	int		y;
	int		calcu;
	int		last_move;
}	t_blinky;

// Struct for inky
typedef struct s_inky
{
	char	stash;
	int		x;
	int		y;
	int		calcu;
	int		last_move;
}	t_inky;

// Struct for pinky
typedef struct s_pinky
{
	char	stash;
	int		x;
	int		y;
	int		calcu;
	int		last_move;
}	t_pinky;

// Struct for clyde
typedef struct s_clyde
{
	char	stash;
	int		x;
	int		y;
	int		last_move;
}	t_clyde;

// Struct of all enemy
typedef struct s_enemy
{
	t_blinky	blinky;
	t_inky		inky;
	t_pinky		pinky;
	t_clyde		clyde;
}	t_enemy;

// Struct to check the number of entity
typedef struct s_entitys_check
{
	int	player_check;
	int	exit_check;
	int	item_check;
	int	enemy_check;
}	t_entity_check;

typedef struct s_help
{
	void		*screen;
	int			frame;
	t_mlx_img	img;
}	t_help;

// Important struct to manage the mlx
typedef struct s_mlx_data
{
	void			*link;
	void			*screen;
	int				current_frame;
	char			*pseudo;
	t_mlx_all_img	img;
	t_mlx_map		map;
	t_enemy			enemy;
	t_player		player;
	t_help			help;
}	t_mlx_data;

// Enum for the mouvement of player or enemy
enum e_movement
{
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4,
};

// typedef usefull for encoding color
typedef unsigned char	t_byte;

//_________________FUNC_________________

// Player movement
char	**player_move(t_mlx_data *data, t_mlx_map *map, int move);
void	print_player(t_mlx_data *data);
void	check_enemy_gameover(t_mlx_data *data, t_mlx_map *map, int move);

// Comon gest
void	init_img(t_mlx_data *data);
void	init_map(t_mlx_data *data);
void	check_item_counter(t_mlx_data *data, t_mlx_map *map, int move);
char	**split_map(char *file_name);
void	map_xy_size(t_mlx_map *map);
void	print_map(t_mlx_data *data);
void	get_entity_pos(t_mlx_map *map, char entity, int index);
void	check_end(t_mlx_data *data, t_mlx_map *map, int move);

// Checker
int		check_wall(t_mlx_map *map);
int		check_entitys_in_map(char **map);
void	check_gameover(t_mlx_data *data, t_mlx_map *map, int move);
int		check_map_rectangle(char **map);
int		entity_counter(char **map, char entity);
int		check_other_char_in_map(char **map);
char	**create_temp_map(char **map);
int		is_valid_path(char **map, int x, int y);

// Utiles
int		files_count_line(char *file_name);
int		screen_color(t_mlx_data *data, int x_size, int y_size, int color);
int		encode_trgb(int t, int r, int g, int b);
int		ft_my_strlen(char *s);
int		ft_strslen(char **map);
void	free_2d_mlx(char **tab);
int		is_in_set(char pos, char *set);
void	taking_pos(t_mlx_data *data);
void	ft_perror(char *str, t_mlx_data *data);

// Scoreboard
void	save_in_scoreboard(t_mlx_data *data);
void	save_in_scoreboard_pt2(t_mlx_data *data, char ***score, char ***user);
void	split_score(int fd, char ***score, char ***user);
int		get_index_of_user(char **user, char	*pseudo, int *index);
int		comp_score(char **score, int new_score, int index);
void	creat_new_score(char ***user, char ***score, t_mlx_data *data);
void	add_score(char *player_name, char *player_score, int fd);
void	sort_score(char ***user, char ***score);
char	**add_data_in_tab(char *data, char **tab);
void	print_scoreboard(char **user, char **score);
void	add_spaces_right(char *str, int width);
void	add_spaces_left(char *str, int width);
char	*encrypt(char *data);

// Tp gest
int		check_tp(char entity, t_mlx_map *map, int move);
void	touch_tp(char entity, char which, t_mlx_map *map);
int		next_move(char entity, t_mlx_data *data);

// Enemy
void	check_player_gameover(t_mlx_data *data, t_mlx_map *map, int move);

char	**blinky_move(t_mlx_data *data, t_mlx_map *map);
char	**blinky_move_pt2(t_mlx_data *data, t_mlx_map *map, char temp, int move);
int		blinky_move_algo(t_mlx_data *data, t_mlx_map *map);
int		blinky_best_move(t_mlx_data *data, int best_move, int actual_move);
void	print_blinky(t_mlx_data *data);

char	**pinky_move(t_mlx_data *data, t_mlx_map *map);
char	**pinky_move_pt2(t_mlx_data *data, t_mlx_map *map, int move, char temp);
int		pinky_move_algo(t_mlx_data *data, t_pinky *pinky, t_mlx_map *map);
int		pinky_best_move(t_mlx_data *data, int best_move, int actual_move);
int		pinky_best_move_pt2(t_mlx_data *data, int actual_move, int target_x, int target_y);
void	print_pinky(t_mlx_data *data);

char	**inky_move(t_mlx_data *data, t_mlx_map *map);
char **inky_move_pt2(t_mlx_data *data, t_mlx_map *map, int move, char temp);
int		inky_move_algo(t_mlx_data *data, t_mlx_map *map);
int		inky_best_move(t_mlx_data *data, int best_move, int actual_move);
void	print_inky(t_mlx_data *data);

char	**clyde_move(t_mlx_data *data, t_mlx_map *map);
char	**clyde_move_pt2(t_mlx_data *data, t_mlx_map *map, int rdm, char temp);
void	print_clyde(t_mlx_data *data);

// MLX gest
void	mlx_draw_rectangle(t_mlx_data *data, t_mlx_draw draw);
int		handle_input(int keysym, t_mlx_data *data);
int		mlx_destroy(t_mlx_data *data);

#endif
