/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:10:42 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/14 18:40:37 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//_________________MACROS_________________
# define TEXTUR_SIZE 32
# define RED 0, 255, 0, 0
# define GREEN 0, 0, 255, 0
# define BLUE 0, 0, 0, 255
# define TESTER ft_printf("\ntester\n");

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


//_________________STRUCT&ENUM_________________

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

typedef struct s_mlx_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_mlx_img;

typedef struct s_mlx_all_img
{
	t_mlx_img character;
	t_mlx_img item;
	t_mlx_img floor;
	t_mlx_img wall;
	t_mlx_img exit;
	t_mlx_img enemy;
	int x;
	int y;
} t_mlx_all_img;

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
}	t_mlx_map;

typedef struct s_mlx_data
{
	void			*link;
	void			*screen;
	int				current_frame;
	t_mlx_all_img	img;
	t_mlx_map		map;
}	t_mlx_data;

typedef struct s_entitys_check
{
	int	player_check;
	int	exit_check;
	int	item_check;
	int	enemy_check;
}	t_entity_check;

typedef struct s_enemy
{
	int		index;
	char	stash;
	int		pos_x;
	int		pos_y;
	void	*next;
}	t_enemy;

enum movement
{
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4,
};

typedef unsigned char	byte;

//_________________FUNC_________________
char	**player_move(t_mlx_data *data, t_mlx_map *map, int move);
void	check_item_counter(t_mlx_map *map, int move);
void	mlx_draw_rectangle(t_mlx_data *data, t_mlx_draw draw);
int		encode_trgb(int t, int r, int g, int b);
int		mlx_destroy(t_mlx_data *data);
int		screen_color(t_mlx_data *data, int x_size, int y_size, int color);
void	mlx_draw_circle(int pos_x, int pos_y, int radius, int color, t_mlx_data *data);
int		files_count_line(char *file_name);
char	**split_map(char *file_name);
void	map_xy_size(t_mlx_map *map);
int		check_wall(t_mlx_map *map);
int		check_entitys_in_map(char **map);
void	print_map(t_mlx_data *data);
void	init_img(t_mlx_data *data);
int		handle_input(int keysym, t_mlx_data *data);
void	get_entity_pos(t_mlx_map *map, char entity, int index);
int		entity_counter(char **map, char entity);
void	check_end(t_mlx_data *data, t_mlx_map *map, int move);
void	check_gameover(t_mlx_data *data, t_mlx_map *map, int move);
void	init_map(t_mlx_data *data);
int		check_map_rectangle(char **map);
int		ft_my_strlen(char *s);
int		check_other_char_in_map(char **map);
int		is_valid_path(char **map, int x, int y);
char	**create_temp_map(char **map);
int		ft_strslen(char **map);
void	free_2d(char **tab);
void	check_enemy_gameover(t_mlx_data *data, t_mlx_map *map, int move);
char	**enemy_move(t_mlx_data *data, t_mlx_map *map, int index);
void	check_player_gameover(t_mlx_data *data, t_mlx_map *map, int move);
t_enemy *lst_create_enemy(int index, int pos_x, int pos_y);
t_enemy *lst_add_enemy(t_enemy *lst, t_enemy *new);
#endif
