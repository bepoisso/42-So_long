/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:55:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/10/25 11:38:27 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	screen_color(t_mlx_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while(y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			mlx_pixel_put(data->link, data->screen, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

int	mlx_destroy(t_mlx_data *data)
{
	if (data->screen)
		mlx_destroy_window(data->link, data->screen);
	if (data->link)
		mlx_destroy_display(data->link);
	exit (0);
	return (1);
}

int	encode_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
