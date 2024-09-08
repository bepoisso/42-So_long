/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/09/08 18:41:59 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

int	change_color(t_mlx_data *data, int color)
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

int	hadndle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->link, data->screen);
		mlx_destroy_display(data->link);
		free(data->link);
		exit(1);
	}
	if (keysym == XK_r)
		change_color(data, encode_rgb(255, 0, 0));
	if (keysym == XK_g)
		change_color(data, encode_rgb(0, 255, 0));
	if (keysym == XK_b)
		change_color(data, encode_rgb(0, 0, 255));
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.link = mlx_init();
	data.screen = mlx_new_window(data.link, SIZE_X, SIZE_Y, "So_long");
	mlx_key_hook(data.screen, hadndle_input, &data);
	mlx_loop(data.link);
}
