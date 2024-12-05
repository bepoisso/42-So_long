/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:55:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/05 08:43:01 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Draw a rectangle on the window of the mlx
void	mlx_draw_rectangle(t_mlx_data *data, t_mlx_draw draw)
{
	int	x;
	int	y;

	x = draw.x_start;
	while (x < draw.size_x + draw.x_start)
	{
		y = draw.y_start;
		while (y < draw.size_y + draw.y_start)
		{
			mlx_pixel_put(data->link, data->screen, draw.x_start,
				draw.y_start, draw.color);
			y++;
		}
		x++;
	}
}

// Set a color for the entier screen of the mlx
int	screen_color(t_mlx_data *data, int x_size, int y_size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < y_size)
	{
		x = 0;
		while (x < x_size)
		{
			mlx_pixel_put(data->link, data->screen, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

// Destroy and free at the end of the game or if a error appeares
int	mlx_destroy(t_mlx_data *data)
{
	if (data->screen)
		mlx_destroy_window(data->link, data->screen);
	if (data->img.character1.img)
		mlx_destroy_image(data->link, data->img.character1.img);
	if (data->img.character_left.img)
		mlx_destroy_image(data->link, data->img.character_left.img);
	if (data->img.character_right.img)
		mlx_destroy_image(data->link, data->img.character_right.img);
	if (data->img.character_up.img)
		mlx_destroy_image(data->link, data->img.character_up.img);
	if (data->img.character_down.img)
		mlx_destroy_image(data->link, data->img.character_down.img);
	if (data->img.wall.img)
		mlx_destroy_image(data->link, data->img.wall.img);
	if (data->img.floor.img)
		mlx_destroy_image(data->link, data->img.floor.img);
	if (data->img.item.img)
		mlx_destroy_image(data->link, data->img.item.img);
	if (data->img.exit.img)
		mlx_destroy_image(data->link, data->img.exit.img);
	if (data->img.exit1.img)
		mlx_destroy_image(data->link, data->img.exit1.img);
	if (data->img.blinky.img)
		mlx_destroy_image(data->link, data->img.blinky.img);
	if (data->img.blinky.img_down)
		mlx_destroy_image(data->link, data->img.blinky.img_down);
	if (data->img.blinky.img_left)
		mlx_destroy_image(data->link, data->img.blinky.img_left);
	if (data->img.blinky.img_right)
		mlx_destroy_image(data->link, data->img.blinky.img_right);
	if (data->img.pinky.img)
		mlx_destroy_image(data->link, data->img.pinky.img);
	if (data->img.pinky.img_down)
		mlx_destroy_image(data->link, data->img.pinky.img_down);
	if (data->img.pinky.img_left)
		mlx_destroy_image(data->link, data->img.pinky.img_left);
	if (data->img.pinky.img_right)
		mlx_destroy_image(data->link, data->img.pinky.img_right);
	if (data->img.inky.img)
		mlx_destroy_image(data->link, data->img.inky.img);
	if (data->img.inky.img_down)
		mlx_destroy_image(data->link, data->img.inky.img_down);
	if (data->img.inky.img_left)
		mlx_destroy_image(data->link, data->img.inky.img_left);
	if (data->img.inky.img_right)
		mlx_destroy_image(data->link, data->img.inky.img_right);
	if (data->img.clyde.img)
		mlx_destroy_image(data->link, data->img.clyde.img);
	if (data->img.clyde.img_down)
		mlx_destroy_image(data->link, data->img.clyde.img_down);
	if (data->img.clyde.img_left)
		mlx_destroy_image(data->link, data->img.clyde.img_left);
	if (data->img.clyde.img_right)
		mlx_destroy_image(data->link, data->img.clyde.img_right);
	if (data->map.map)
		free_2d_mlx(data->map.map);
	if (data->map.temp_map)
		free_2d_mlx(data->map.temp_map);
	if (data->help.img.img)
		mlx_destroy_image(data->help.link, data->help.img.img);
	if (data->help.screen)
		mlx_destroy_window(data->help.link, data->help.screen);
	if (data->help.link)
	{
		mlx_destroy_display(data->help.link);
		free(data->help.link);
	}
	if (data->link)
	{
		mlx_destroy_display(data->link);
		free(data->link);
	}
	if (data->status == 1)
		exit (1);
	exit (0);
}

// Encoding rgb (Yes the t of trgb is usless because the mlx dont manage it)
int	encode_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// Free a char tab of 2 dimentions
void	free_2d_mlx(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
