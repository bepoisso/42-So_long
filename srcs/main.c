/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:41:48 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/08 12:10:04 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_help(int keysym, t_mlx_data *data)
{
	ft_printf("%d\n", keysym);
	if (keysym == XK_Escape)
	{
		mlx_destroy(data);
		exit(0);
	}
	if (keysym == XK_space)
	{
		mlx_loop_end(data->help.link);
	}
	return (0);
}

int	update_frame_help(t_mlx_data *data)
{
	data->current_frame++;
	while (data->current_frame > 5000)
	{
		data->current_frame = 0;
		if (data->help.frame == 1)
		{
			mlx_put_image_to_window(data->help.link, data->help.screen,
				data->help.img.img, 0, 0);
			data->help.frame = 2;
		}
		else if (data->help.frame == 2)
		{
			mlx_put_image_to_window(data->help.link, data->help.screen,
				data->help.img.img_down, 0, 0);
			data->help.frame = 3;
		}
		update_frame_pt2(data);
	}
	return (0);
}

void	update_frame_pt2(t_mlx_data *data)
{
	if (data->help.frame == 3)
	{
		mlx_put_image_to_window(data->help.link, data->help.screen,
			data->help.img.img_left, 0, 0);
		data->help.frame = 4;
	}
	else if (data->help.frame == 4)
	{
		mlx_put_image_to_window(data->help.link, data->help.screen,
			data->help.img.img_right, 0, 0);
		data->help.frame = 1;
	}
}

int	init_help(t_mlx_data *data)
{
	data->help.link = mlx_init();
	if (!data->help.link)
		ft_printf("ERROR INIT\n");
	data->help.screen = mlx_new_window(data->help.link, 500, 500, "HELP PAGE");
	if (!data->help.screen)
		ft_printf("ERROR screen\n");
	init_help_img(data);
	if (!data->help.img.img)
		ft_printf("ERROR IMG\n");
	mlx_key_hook(data->help.screen, key_help, data);
	mlx_hook(data->help.screen, DestroyNotify, NoEventMask,
		mlx_destroy, &data);
	mlx_loop_hook(data->help.link, update_frame_help, data);
	mlx_loop(data->help.link);
	return (0);
}

void	init_help_img(t_mlx_data *data)
{
	data->help.img.path = "./imgs/help_page_1.xpm";
	data->help.img.path_down = "./imgs/help_page_2.xpm";
	data->help.img.path_left = "./imgs/help_page_3.xpm";
	data->help.img.path_right = "./imgs/help_page_4.xpm";
	data->help.img.img = mlx_xpm_file_to_image(data->help.link,
			data->help.img.path, &data->help.img.height,
			&data->help.img.width);
	data->help.img.img_down = mlx_xpm_file_to_image(data->help.link,
			data->help.img.path_down, &data->help.img.height,
			&data->help.img.width);
	data->help.img.img_left = mlx_xpm_file_to_image(data->help.link,
			data->help.img.path_left, &data->help.img.height,
			&data->help.img.width);
	data->help.img.img_right = mlx_xpm_file_to_image(data->help.link,
			data->help.img.path_right, &data->help.img.height,
			&data->help.img.width);
}

int	main(int ac, char **av)
{
	t_mlx_data	data;

	ft_memset(&data, 0, sizeof(t_mlx_data));
	init_value(&data, av);
	if (ac < 2)
		return (ft_perror("***MISSING ARGUMENT**\n./solong \"login42\"\n",
				&data), 1);
	init_help(&data);
	data.link = mlx_init();
	if (!data.link)
		ft_perror("***ERROR MLX_INIT***\n\n", &data);
	data.screen = mlx_new_window(data.link, TEXTUR_SIZE * data.map.x_max,
			TEXTUR_SIZE * (data.map.y_max + 2), "PACMAN");
	if (!data.screen)
		ft_perror("***ERROR SCREEN***\n\n", &data);
	init_img(&data);
	mlx_hook(data.screen, DestroyNotify, NoEventMask, mlx_destroy, &data);
	print_map(&data);
	mlx_key_hook(data.screen, handle_input, &data);
	mlx_loop_hook(data.link, update_frame, &data);
	mlx_loop(data.link);
}
