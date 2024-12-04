/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/04 08:45:50 by bepoisso         ###   ########.fr       */
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
	if (keysym == 119 && keysym == 65362)
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, UP);
		data->player.last_move = UP;
		print_map(data);
	}
	if (keysym == 97 && keysym == 65361)
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, LEFT);
		data->player.last_move = LEFT;
		print_map(data);
	}
	if (keysym == 115 && keysym == 65364)
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, DOWN);
		data->player.last_move = DOWN;
		print_map(data);
	}
	if (keysym == 100 && keysym == 65363)
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, RIGHT);
		data->player.last_move = RIGHT;
		print_map(data);
	}
	ft_printf("\nMouvement counter = %d\n", data->map.move_count);
	ft_printf("keysym = %d\n", keysym);
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
	return (0);
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

// Printing the map on the mlx window
void	print_map(t_mlx_data *data)
{
	data->map.y = 0;
	data->img.y = 0;
	while (data->map.map[data->map.y] != NULL)
	{
		data->map.x = 0;
		data->img.x = 0;
		while (data->map.map[data->map.y][data->map.x] != '\0')
		{
			if (data->map.map[data->map.y][data->map.x] == '0'
				|| data->map.map[data->map.y][data->map.x] == 'T')
				mlx_put_image_to_window(data->link, data->screen,
					data->img.floor.img, data->img.x, data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == '1')
				mlx_put_image_to_window(data->link, data->screen,
					data->img.wall.img, data->img.x, data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'C')
				mlx_put_image_to_window(data->link, data->screen,
					data->img.item.img, data->img.x, data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'E')
			{
				if (data->map.item != 0)
					mlx_put_image_to_window(data->link, data->screen,
						data->img.exit.img, data->img.x, data->img.y);
				else
					mlx_put_image_to_window(data->link, data->screen,
						data->img.exit1.img, data->img.x, data->img.y);
			}
			else if (data->map.map[data->map.y][data->map.x] == 'P')
				print_player(data);
			else if (data->map.map[data->map.y][data->map.x] == 'W')
				print_blinky(data);
			else if (data->map.map[data->map.y][data->map.x] == 'X')
				print_pinky(data);
			else if (data->map.map[data->map.y][data->map.x] == 'Y')
				print_inky(data);
			else if (data->map.map[data->map.y][data->map.x] == 'Z')
				print_clyde(data);
			data->map.x++;
			data->img.x += TEXTUR_SIZE;
		}
		data->map.y++;
		data->img.y += TEXTUR_SIZE;
	}
}

void	print_clyde(t_mlx_data *data)
{
	if (data->enemy.clyde.last_move == UP)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.clyde.img, data->img.x, data->img.y);
	else if (data->enemy.clyde.last_move == DOWN)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.clyde.img_down, data->img.x, data->img.y);
	else if (data->enemy.clyde.last_move == LEFT)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.clyde.img_left, data->img.x, data->img.y);
	else
		mlx_put_image_to_window(data->link, data->screen,
			data->img.clyde.img_right, data->img.x, data->img.y);
}

void	print_inky(t_mlx_data *data)
{
	if (data->enemy.inky.last_move == UP)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.inky.img, data->img.x, data->img.y);
	else if (data->enemy.inky.last_move == DOWN)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.inky.img_down, data->img.x, data->img.y);
	else if (data->enemy.inky.last_move == LEFT)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.inky.img_left, data->img.x, data->img.y);
	else
		mlx_put_image_to_window(data->link, data->screen,
			data->img.inky.img_right, data->img.x, data->img.y);
}

void	print_pinky(t_mlx_data *data)
{
	if (data->enemy.pinky.last_move == UP)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.pinky.img, data->img.x, data->img.y);
	else if (data->enemy.pinky.last_move == DOWN)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.pinky.img_down, data->img.x, data->img.y);
	else if (data->enemy.pinky.last_move == LEFT)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.pinky.img_left, data->img.x, data->img.y);
	else
		mlx_put_image_to_window(data->link, data->screen,
			data->img.pinky.img_right, data->img.x, data->img.y);
}

void	print_blinky(t_mlx_data *data)
{
	if (data->enemy.blinky.last_move == UP)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.blinky.img, data->img.x, data->img.y);
	else if (data->enemy.blinky.last_move == DOWN)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.blinky.img_down, data->img.x, data->img.y);
	else if (data->enemy.blinky.last_move == LEFT)
		mlx_put_image_to_window(data->link, data->screen,
			data->img.blinky.img_left, data->img.x, data->img.y);
	else
		mlx_put_image_to_window(data->link, data->screen,
			data->img.blinky.img_right, data->img.x, data->img.y);
}

// Print the player all direction or frame aimation
void	print_player(t_mlx_data *data)
{
	if (data->player.img_frame >= 1)
	{
		mlx_put_image_to_window(data->link, data->screen,
			data->img.character1.img, data->img.x, data->img.y);
		data->player.img_frame = 0;
	}
	else if (data->player.img_frame == 0)
	{
		if (data->player.last_move == RIGHT)
			mlx_put_image_to_window(data->link, data->screen,
				data->img.character_right.img, data->img.x, data->img.y);
		else if (data->player.last_move == LEFT)
			mlx_put_image_to_window(data->link, data->screen,
				data->img.character_left.img, data->img.x, data->img.y);
		else if (data->player.last_move == UP)
			mlx_put_image_to_window(data->link, data->screen,
				data->img.character_up.img, data->img.x, data->img.y);
		else if (data->player.last_move == DOWN)
			mlx_put_image_to_window(data->link, data->screen,
				data->img.character_down.img, data->img.x, data->img.y);
		data->player.img_frame = 1;
	}
}

// taking all po of all entity
void	taking_pos(t_mlx_data *data)
{
	get_entity_pos(&data->map, PLAYER, 1);
	data->player.x = data->map.x;
	data->player.y = data->map.y;
	get_entity_pos(&data->map, BLINKY, 1);
	data->enemy.blinky.x = data->map.x;
	data->enemy.blinky.y = data->map.y;
	data->enemy.blinky.stash = '0';
	get_entity_pos(&data->map, PINKY, 1);
	data->enemy.pinky.x = data->map.x;
	data->enemy.pinky.y = data->map.y;
	data->enemy.pinky.stash = '0';
	get_entity_pos(&data->map, INKY, 1);
	data->enemy.inky.x = data->map.x;
	data->enemy.inky.y = data->map.y;
	data->enemy.inky.stash = '0';
	get_entity_pos(&data->map, CLYDE, 1);
	data->enemy.clyde.x = data->map.x;
	data->enemy.clyde.y = data->map.y;
	data->enemy.clyde.stash = '0';
}

void	ft_perror(char *str, t_mlx_data *data)
{
	ft_putstr_fd(str, 1);
	data->status = 1;
	mlx_destroy(data);
}

void	init_value(t_mlx_data *data, char **av)
{
	srand(time(NULL));
	data->current_frame = -100000;
	data->map.stach = '0';
	data->pseudo = av[1];
	data->player.last_move = 3;
	init_map(data);
	taking_pos(data);
}
