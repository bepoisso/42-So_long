/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:10:42 by bepoisso          #+#    #+#             */
/*   Updated: 2024/10/14 14:45:03 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//_________________MACROS_________________
# define SIZE_X 1000
# define SIZE_Y 1000
# define RED 0, 255, 0, 0
# define GREEN 0, 0, 255, 0
# define BLUE 0, 0, 0, 255

//_________________INCLUDES_________________
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
#include <X11/X.h>


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

typedef struct s_mlx_data
{
	void	*link;
	void	*screen;
}	t_mlx_data;

typedef struct s_manpi_tab
{
	int		x_max;
	int		y_max;
	int		x;
	int		y;
	char	**map;
	int		item;
}	t_manip_map;

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
char	**player_move(t_manip_map *map, int move);
int		check_item_counter(t_manip_map *map, int move);
void	mlx_draw_rectangle(t_mlx_data *data, t_mlx_draw draw);
int		encode_trgb(int t, int r, int g, int b);
int		mlx_destroy(t_mlx_data *data);
int		screen_color(t_mlx_data *data, int color);
void	mlx_draw_circle(int pos_x, int pos_y, int radius, int color, t_mlx_data *data);

#endif
