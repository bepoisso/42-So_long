/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_pt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:42:43 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/08 12:43:14 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img_pt6(t_mlx_data *data)
{
	if (!data->img.character1.img)
		ft_perror("\nERROR loading character1 image\n", data);
	if (!data->img.blinky.img || !data->img.blinky.img_down
		|| !data->img.blinky.img_left || !data->img.blinky.img_right)
		ft_perror("\nERROR loading clyde image\n", data);
	if (!data->img.pinky.img || !data->img.pinky.img_down
		|| !data->img.pinky.img_left || !data->img.pinky.img_right)
		ft_perror("\nERROR loading pinky image\n", data);
	if (!data->img.inky.img || !data->img.inky.img_down
		|| !data->img.inky.img_left || !data->img.inky.img_right)
		ft_perror("\nERROR loading inky image\n", data);
	if (!data->img.clyde.img || !data->img.clyde.img_down
		|| !data->img.clyde.img_left || !data->img.clyde.img_right)
		ft_perror("\nERROR loading clyde image\n", data);
}

void	init_img_pt5(t_mlx_data *data)
{
	data->img.clyde.img_down
		= mlx_xpm_file_to_image(data->link, data->img.clyde.path_down,
			&data->img.clyde.width, &data->img.clyde.height);
	data->img.clyde.img_left
		= mlx_xpm_file_to_image(data->link, data->img.clyde.path_left,
			&data->img.clyde.width, &data->img.clyde.height);
	data->img.clyde.img_right
		= mlx_xpm_file_to_image(data->link, data->img.clyde.path_right,
			&data->img.clyde.width, &data->img.clyde.height);
	if (!data->img.floor.img)
		ft_perror("\nERROR loading floor image\n", data);
	if (!data->img.wall.img)
		ft_perror("\nERROR loading wall image\n", data);
	if (!data->img.item.img)
		ft_perror("\nERROR loading item image\n", data);
	if (!data->img.exit.img || !data->img.exit1.img)
		ft_perror("\nERROR loading exit image\n", data);
	if (!data->img.character_left.img)
		ft_perror("\nERROR loading character_left image\n", data);
	if (!data->img.character_right.img)
		ft_perror("\nERROR loading character_right image\n", data);
	if (!data->img.character_up.img)
		ft_perror("\nERROR loading character_up image\n", data);
	if (!data->img.character_down.img)
		ft_perror("\nERROR loading character_down image\n", data);
}
