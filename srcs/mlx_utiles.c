/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:55:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/08 13:02:56 by bepoisso         ###   ########.fr       */
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

void	ft_perror(char *str, t_mlx_data *data)
{
	ft_putstr_fd(str, 1);
	data->status = 1;
	mlx_destroy(data);
}
