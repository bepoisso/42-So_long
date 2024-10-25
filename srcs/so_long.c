/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/10/25 12:20:32 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy(data);
		exit(1);
	}
	if (keysym == 122) // UP
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, UP);
		data->map.move_count++;
		print_map(data);
	}
	if (keysym == 113) // LEFT
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, LEFT);
		data->map.move_count++;
		print_map(data);
	}
	if (keysym == 115) // DOWN
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, DOWN);
		data->map.move_count++;
		print_map(data);
	}
	if (keysym == 100) // RIGHT
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, RIGHT);
		data->map.move_count++;
		print_map(data);
	}
	ft_printf("\nMouvement counter = %d\n", data->map.move_count);
	return (0);
}

void	init_img(t_mlx_data *data)
{
	data->img.floor.path = "./skin/pac/floor.xpm";
	data->img.wall.path = "./skin/pac/wall.xpm";
	data->img.item.path = "./skin/pac/item.xpm";
	data->img.exit.path = "./skin/pac/exit.xpm";
	data->img.character.path = "./skin/pac/character.xpm";

	data->img.floor.img = mlx_xpm_file_to_image(data->link, data->img.floor.path, &data->img.floor.width, &data->img.floor.height);
	if (!data->img.floor.img)
		ft_printf("\nERROR loading floor image\n");

	data->img.wall.img = mlx_xpm_file_to_image(data->link, data->img.wall.path, &data->img.wall.width, &data->img.wall.height);
	if (!data->img.wall.img)
		ft_printf("\nERROR loading wall image\n");

	data->img.item.img = mlx_xpm_file_to_image(data->link, data->img.item.path, &data->img.item.width, &data->img.item.height);
	if (!data->img.item.img)
		ft_printf("\nERROR loading item image\n");

	data->img.exit.img = mlx_xpm_file_to_image(data->link, data->img.exit.path, &data->img.exit.width, &data->img.exit.height);
	if (!data->img.exit.img)
		ft_printf("\nERROR loading exit image\n");

	data->img.character.img = mlx_xpm_file_to_image(data->link, data->img.character.path, &data->img.character.width, &data->img.character.height);
	if (!data->img.character.img)
		ft_printf("\nERROR loading character image\n");
}

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
			if (data->map.map[data->map.y][data->map.x] == '0')
				mlx_put_image_to_window(data->link, data->screen, data->img.floor.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == '1')
				mlx_put_image_to_window(data->link, data->screen, data->img.wall.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'C')
				mlx_put_image_to_window(data->link, data->screen, data->img.item.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'E')
				mlx_put_image_to_window(data->link, data->screen, data->img.exit.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'P')
				mlx_put_image_to_window(data->link, data->screen, data->img.character.img, data->img.x ,data->img.y);
			data->map.x++;
			data->img.x += TEXTUR_SIZE;
		}
		data->map.y++;
		data->img.y += TEXTUR_SIZE;
	}
}

int	main(void)
{
	t_mlx_data	data;

	data.link = mlx_init();
	if (!data.link)
		ft_printf("***ERROR INIT***\n\n");

	data.screen = mlx_new_window(data.link, SIZE_X, SIZE_Y, "So_long");
	if (!data.screen)
		ft_printf("***ERROR SCREEN***\n\n");

	// Gestions des la croix (X)
	mlx_hook(data.screen, DestroyNotify, NoEventMask, mlx_destroy, &data);
	
	//Gestion map
	init_map(&data);
	/* data.map.map = split_map("./map.test");
	data.map.move_count = 0;
	data.map.item = item_counter(data.map.map); */
	
	//Gestion de l'impression tableau
	init_img(&data);
	print_map(&data);
	
	// Gestion des événements clavier
	mlx_key_hook(data.screen, handle_input, &data);
	mlx_loop(data.link);
}

