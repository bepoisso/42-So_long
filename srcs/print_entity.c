/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:59:36 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/08 13:01:35 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
