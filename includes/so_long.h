/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:10:42 by bepoisso          #+#    #+#             */
/*   Updated: 2024/09/07 20:05:34 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//_________________MACROS_________________

//_________________INCLUDES_________________
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>


//_________________STRUCT&ENUM_________________
typedef struct s_mlx_data
{
	void	*link;
	void	*screen;
}	t_mlx_data;

typedef struct s_manpi_tab
{
	int	x_max;
	int	y_max;
	int	x;
	int	y;
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

#endif
