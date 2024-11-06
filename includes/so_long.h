/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:10:42 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/04 17:35:27 by bepoisso         ###   ########.fr       */
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
	int x;
	int y;
} t_mlx_all_img;

typedef struct s_mlx_map
{
	char	**map;
	int		x;
	int		y;
	int		x_max;
	int		y_max;
	int		item;
	int		move_count;
}	t_mlx_map;

typedef struct s_mlx_data
{
	void			*link;
	void			*screen;
	t_mlx_all_img	img;
	t_mlx_map		map;
}	t_mlx_data;

typedef struct s_entitys_check
{
	int	player_check;
	int	exit_check;
	int	item_check;
}	t_entity_check;

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
void	get_player_pos(t_mlx_map *map);
int		item_counter(char **map);
void	check_end(t_mlx_data *data, t_mlx_map *map, int move);
void	check_gameover(t_mlx_data *data, t_mlx_map *map, int move);
void	init_map(t_mlx_data *data);
int		check_map_rectangle(char **map);
int		ft_my_strlen(char *s);
int		check_other_char_in_map(char **map);
int		is_valid_path(char **map, int x, int y);
#endif
