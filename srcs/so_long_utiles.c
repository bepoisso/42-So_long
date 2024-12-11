/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/11 16:28:51 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Taking information if a key pressed and transfert to the right function
// UP 119 - 122 | DOWN 115 - 65364 | LEFT 97 - 113 | RIGHT 100 - 65363
int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy(data);
		exit(0);
	}
	if (keysym == 119 || keysym == 65362)
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, UP);
		data->player.last_move = UP;
		print_map(data);
	}
	if (keysym == 97 || keysym == 65361)
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, LEFT);
		data->player.last_move = LEFT;
		print_map(data);
	}
	handle_input_pt2(keysym, data);
	handle_input_pt3(data);
	return (0);
}

void	handle_input_pt2(int keysym, t_mlx_data *data)
{
	if (keysym == 115 || keysym == 65364)
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, DOWN);
		data->player.last_move = DOWN;
		print_map(data);
	}
	if (keysym == 100 || keysym == 65363)
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, RIGHT);
		data->player.last_move = RIGHT;
		print_map(data);
	}
}

void	handle_input_pt3(t_mlx_data *data)
{
	ft_printf("\nMouvement counter = %d\n", data->map.move_count);
	data->temp = ft_itoa(data->map.move_count);
	mlx_string_put(data->link, data->screen, 0, TEXTUR_SIZE
		* (data->map.y_max + 2), encode_trgb(0, 255, 255, 255),
		"Mouvement count : ");
	mlx_string_put(data->link, data->screen, 110, TEXTUR_SIZE
		* (data->map.y_max + 2), encode_trgb(0, 255, 255, 255), data->temp);
	free(data->temp);
	data->temp = ft_itoa(data->map.item);
	mlx_string_put(data->link, data->screen, 0, TEXTUR_SIZE
		* (data->map.y_max + 1) + 10, encode_trgb(0, 255, 255, 255),
		"Item count : ");
	mlx_string_put(data->link, data->screen, 110, TEXTUR_SIZE
		* (data->map.y_max + 1) + 10, encode_trgb(0, 255, 255, 255),
		data->temp);
	free(data->temp);
}

// Update the frame of the game. Utiles for the mouvement of enemy
// and animation
// UPDATE FRAME 15000
// UPDTATE ANIMATION 5000 | 10000
int	update_frame(t_mlx_data *data)
{
	data->current_frame++;
	if (data->current_frame > 15000)
	{
		data->map.map = blinky_move(data, &data->map);
		data->map.map = inky_move(data, &data->map);
		data->map.map = pinky_move(data, &data->map);
		data->map.map = clyde_move(data, &data->map);
		print_map(data);
		data->current_frame = 0;
	}
	if (data->current_frame == 5000 || data->current_frame == 10000)
		print_map(data);
	return (0);
}

// Get the number of list in a 2D char tab (char tab[THIS][])
int	ft_strslen(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}
