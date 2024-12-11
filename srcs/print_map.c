/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:01:42 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/11 15:32:16 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
				|| data->map.map[data->map.y][data->map.x] == 'T'
				|| data->map.map[data->map.y][data->map.x] == 't')
				mlx_put_image_to_window(data->link, data->screen,
					data->img.floor.img, data->img.x, data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'C')
				mlx_put_image_to_window(data->link, data->screen,
					data->img.item.img, data->img.x, data->img.y);
			else
				print_map_pt2(data);
			data->map.x++;
			data->img.x += TEXTUR_SIZE;
		}
		data->map.y++;
		data->img.y += TEXTUR_SIZE;
	}
}

void	print_map_pt2(t_mlx_data *data)
{
	if (data->map.map[data->map.y][data->map.x] == 'E')
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
	else if (data->map.map[data->map.y][data->map.x] == '1')
		mlx_put_image_to_window(data->link, data->screen,
			data->img.wall.img, data->img.x, data->img.y);
}
