/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/21 14:03:47 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Taking information if a key is poress and transfert to the right function
int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape) // CLOSE ON ESC
	{
		mlx_destroy(data);
		exit(1);
	}
	if (keysym == 119) // UP 119 - 122
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, UP);
		data->map.move_count++;
		print_map(data);
	}
	if (keysym == 97) // LEFT 97 - 113
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, LEFT);
		data->map.move_count++;
		print_map(data);
	}
	if (keysym == 115) // DOWN 115
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, DOWN);
		data->map.move_count++;
		print_map(data);
	}
	if (keysym == 100) // RIGHT 100
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, RIGHT);
		data->map.move_count++;
		print_map(data);
	}
	ft_printf("Keysym = %d\n", keysym);
	ft_printf("\nMouvement counter = %d\n", data->map.move_count);
	mlx_string_put(data->link, data->screen, 0, TEXTUR_SIZE * (data->map.y_max + 2), encode_trgb(0, 255, 255, 255), "Mouvement count : ");
	mlx_string_put(data->link, data->screen, 110, TEXTUR_SIZE * (data->map.y_max + 2), encode_trgb(0, 255, 255, 255), ft_itoa(data->map.move_count));

	mlx_string_put(data->link, data->screen, 0, TEXTUR_SIZE * (data->map.y_max + 1) + 10, encode_trgb(0, 255, 255, 255), "Item count : ");
	mlx_string_put(data->link, data->screen, 110, TEXTUR_SIZE * (data->map.y_max + 1) + 10, encode_trgb(0, 255, 255, 255), ft_itoa(data->map.item));
	return (0);
}

// Update the frame of the game. Utiles for the mouvement of enemy
// And Animation
int	update_frame(t_mlx_data *data)
{
	data->current_frame++;
	if (data->current_frame > 15000) // UPDATE FRAME 15000
	{
		data->map.map = enemy_move(data, &data->map, 1, 'W');
		data->map.map = enemy_move(data, &data->map, 1, 'X');
		data->map.map = enemy_move(data, &data->map, 1, 'Y');
		data->map.map = enemy_move(data, &data->map, 1, 'Z');
		print_map(data);
		ft_printf("\nFrame updated\n");
		data->current_frame = 0;
	}
	return (0);
}

// Initalise all image in a struct
void	init_img(t_mlx_data *data)
{
	data->img.floor.path = "./skin/pac/floor.xpm";
	data->img.wall.path = "./skin/pac/wall.xpm";
	data->img.item.path = "./skin/pac/item.xpm";
	data->img.exit.path = "./skin/pac/exit.xpm";
	data->img.character.path = "./skin/pac/character.xpm";
	data->img.enemy.path = "./skin/pac/enemy.xpm";
	data->img.enemy1.path = "./skin/pac/enemy1.xpm";
	data->img.enemy2.path = "./skin/pac/enemy2.xpm";
	data->img.enemy3.path = "./skin/pac/enemy3.xpm";

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

	data->img.enemy.img = mlx_xpm_file_to_image(data->link, data->img.enemy.path, &data->img.enemy.width, &data->img.enemy.height);
	if (!data->img.enemy.img)
	ft_printf("\nERROR loading enemy image\n");

	data->img.enemy1.img = mlx_xpm_file_to_image(data->link, data->img.enemy1.path, &data->img.enemy1.width, &data->img.enemy1.height);
	if (!data->img.enemy1.img)
	ft_printf("\nERROR loading enemy1 image\n");

	data->img.enemy2.img = mlx_xpm_file_to_image(data->link, data->img.enemy2.path, &data->img.enemy2.width, &data->img.enemy2.height);
	if (!data->img.enemy2.img)
	ft_printf("\nERROR loading enemy2 image\n");

	data->img.enemy3.img = mlx_xpm_file_to_image(data->link, data->img.enemy3.path, &data->img.enemy3.width, &data->img.enemy3.height);
	if (!data->img.enemy3.img)
	ft_printf("\nERROR loading enemy3 image\n");
}

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
			else if (data->map.map[data->map.y][data->map.x] == 'W')
				mlx_put_image_to_window(data->link, data->screen, data->img.enemy.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'X')
				mlx_put_image_to_window(data->link, data->screen, data->img.enemy1.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'Y')
				mlx_put_image_to_window(data->link, data->screen, data->img.enemy2.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'Z')
				mlx_put_image_to_window(data->link, data->screen, data->img.enemy3.img, data->img.x ,data->img.y);
			data->map.x++;
			data->img.x += TEXTUR_SIZE;
		}
		data->map.y++;
		data->img.y += TEXTUR_SIZE;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (ft_printf("***MISSING ARGUMENT**\n./solong \"login42\"\n"), 1);
	t_mlx_data	data;
	data.current_frame = 0;
	data.map.stach = '0';
	data.pseudo = av[1];

	//Gestion map
	init_map(&data);

	data.link = mlx_init();
	if (!data.link)
		ft_printf("***ERROR INIT***\n\n");

	data.screen = mlx_new_window(data.link, TEXTUR_SIZE * data.map.x_max, TEXTUR_SIZE * (data.map.y_max + 2), "So_long");
	if (!data.screen)
		ft_printf("***ERROR SCREEN***\n\n");

	// Gestions des la croix (X)
	mlx_hook(data.screen, DestroyNotify, NoEventMask, mlx_destroy, &data);
	
	
	//Gestion de l'impression tableau
	init_img(&data);
	print_map(&data);
	
	// Gestion des événements clavier
	mlx_key_hook(data.screen, handle_input, &data);
	mlx_loop_hook(data.link, update_frame, &data);
	mlx_loop(data.link);
}
