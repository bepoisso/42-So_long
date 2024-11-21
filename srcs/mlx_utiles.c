/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:55:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/21 12:56:59 by bepoisso         ###   ########.fr       */
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
		y  = draw.y_start;
		while (y < draw.size_y + draw.y_start)
		{
			mlx_pixel_put(data->link, data->screen, draw.x_start, draw.y_start, draw.color);
			y++;
		}
		x++;
	}
}

// Draw a circle on the window of the mlx
void	mlx_draw_circle(int pos_x, int pos_y, int radius, int color, t_mlx_data *data)
{
	int	x;
	int	y;
	int	distance_squared;
	int	radius_squared;

	radius_squared = radius * radius;
	y = pos_y - radius;
	while (y <= pos_y + radius)
	{
		x = pos_x - radius;
		while (x <= pos_x + radius)
		{
			distance_squared = (x - pos_x) * (x - pos_x) + (y - pos_y) * (y - pos_y);
			if (distance_squared <= radius_squared)
				mlx_pixel_put(data->link, data->screen, x, y, color);
			x++;
		}
		y++;
	}
}

// Set a color for the entier screen of the mlx
int	screen_color(t_mlx_data *data, int x_size, int y_size, int color)
{
	int	x;
	int	y;

	y = 0;
	while(y < y_size)
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

// Destroy and free at the endo of the game or if a error appeares
int	mlx_destroy(t_mlx_data *data)
{
	if (data->screen)
		mlx_destroy_window(data->link, data->screen);
	if (data->img.character.img)
		mlx_destroy_image(data->link, data->img.character.img);
	if (data->img.wall.img)
		mlx_destroy_image(data->link, data->img.wall.img);
	if (data->img.floor.img)
		mlx_destroy_image(data->link, data->img.floor.img);
	if (data->img.item.img)
		mlx_destroy_image(data->link, data->img.item.img);
	if (data->img.exit.img)
		mlx_destroy_image(data->link, data->img.exit.img);
	if (data->img.enemy.img)
		mlx_destroy_image(data->link, data->img.enemy.img);
	if (data->link)
	{
		mlx_destroy_display(data->link);
		free(data->link);
	}
	free_2d_mlx(data->map.map);
	exit (0);
	return (1);
}

// Encoding rgb (Yes the t of trgb is usless caus the mlx dont manage it)
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
