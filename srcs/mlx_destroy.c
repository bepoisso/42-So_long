/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:35:52 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/10 15:32:06 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_destroy_pt4(t_mlx_data *data)
{
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
}

void	mlx_destroy_pt3(t_mlx_data *data)
{
	if (data->img.clyde.img_down)
		mlx_destroy_image(data->link, data->img.clyde.img_down);
	if (data->img.clyde.img_left)
		mlx_destroy_image(data->link, data->img.clyde.img_left);
	if (data->img.clyde.img_right)
		mlx_destroy_image(data->link, data->img.clyde.img_right);
	if (data->help.img.img)
		mlx_destroy_image(data->help.link, data->help.img.img);
	if (data->help.img.img_down)
		mlx_destroy_image(data->help.link, data->help.img.img_down);
	if (data->help.img.img_left)
		mlx_destroy_image(data->help.link, data->help.img.img_left);
	if (data->help.img.img_right)
		mlx_destroy_image(data->help.link, data->help.img.img_right);
	if (data->map.map)
		free_2d_mlx(data->map.map);
	if (data->map.temp_map)
		free_2d_mlx(data->map.temp_map);
	if (data->map_name)
		free(data->map_name);
	if (data->help.screen)
		mlx_destroy_window(data->help.link, data->help.screen);
}

void	mlx_destroy_pt2(t_mlx_data *data)
{
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
}

void	mlx_destroy_pt1(t_mlx_data *data)
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
}

// Destroy and free at the end of the game or if a error appeares
int	mlx_destroy(t_mlx_data *data)
{
	mlx_destroy_pt1(data);
	mlx_destroy_pt2(data);
	mlx_destroy_pt3(data);
	mlx_destroy_pt4(data);
	if (data->status == 1)
		exit (1);
	exit (0);
}
