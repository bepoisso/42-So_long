/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/25 11:00:55 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Taking information if a key pressed and transfert to the right function
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
		data->player.last_move = UP;
		print_map(data);
	}
	if (keysym == 97) // LEFT 97 - 113
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, LEFT);
		data->player.last_move = LEFT;
		print_map(data);
	}
	if (keysym == 115) // DOWN 115
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, DOWN);
		data->player.last_move = DOWN;
		print_map(data);
	}
	if (keysym == 100) // RIGHT 100
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, RIGHT);
		data->player.last_move = RIGHT;
		print_map(data);
	}
	ft_printf("\nMouvement counter = %d\n", data->map.move_count);
	mlx_string_put(data->link, data->screen, 0, TEXTUR_SIZE * (data->map.y_max + 2), encode_trgb(0, 255, 255, 255), "Mouvement count : ");
	mlx_string_put(data->link, data->screen, 110, TEXTUR_SIZE * (data->map.y_max + 2), encode_trgb(0, 255, 255, 255), ft_itoa(data->map.move_count));
	mlx_string_put(data->link, data->screen, 0, TEXTUR_SIZE * (data->map.y_max + 1) + 10, encode_trgb(0, 255, 255, 255), "Item count : ");
	mlx_string_put(data->link, data->screen, 110, TEXTUR_SIZE * (data->map.y_max + 1) + 10, encode_trgb(0, 255, 255, 255), ft_itoa(data->map.item));
	return (0);
}

// Update the frame of the game. Utiles for the mouvement of enemy
// and animation
int	update_frame(t_mlx_data *data)
{
	data->current_frame++;
	if (data->current_frame > 15000) // UPDATE FRAME 15000
	{
		data->map.map = blinky_move(data, &data->map);
		data->map.map = inky_move(data, &data->map);
		data->map.map = pinky_move(data, &data->map);
		data->map.map = clyde_move(data, &data->map);
		print_map(data);
		data->current_frame = 0;
	}
	if (data->current_frame == 5000 || data->current_frame == 10000) // UPDTATE ANIMATION 5000 | 10000
		print_map(data);
	return (0);
}

// Initalise all image in a struct
void	init_img(t_mlx_data *data)
{
	data->img.floor.path = "./imgs/floor.xpm";
	data->img.wall.path = "./imgs/wall.xpm";
	data->img.item.path = "./imgs/item.xpm";
	data->img.exit.path = "./imgs/exit.xpm";
	data->img.character_left.path = "./imgs/character_left.xpm";
	data->img.character_right.path = "./imgs/character_right.xpm";
	data->img.character_up.path = "./imgs/character_up.xpm";
	data->img.character_down.path = "./imgs/character_down.xpm";
	data->img.character1.path = "./imgs/character1.xpm";
	data->img.enemy.path = "./imgs/enemy.xpm";
	data->img.enemy1.path = "./imgs/enemy1.xpm";
	data->img.enemy2.path = "./imgs/enemy2.xpm";
	data->img.enemy3.path = "./imgs/enemy3.xpm";

	data->img.floor.img = mlx_xpm_file_to_image(data->link, data->img.floor.path, &data->img.floor.width, &data->img.floor.height);
	data->img.wall.img = mlx_xpm_file_to_image(data->link, data->img.wall.path, &data->img.wall.width, &data->img.wall.height);
	data->img.item.img = mlx_xpm_file_to_image(data->link, data->img.item.path, &data->img.item.width, &data->img.item.height);
	data->img.exit.img = mlx_xpm_file_to_image(data->link, data->img.exit.path, &data->img.exit.width, &data->img.exit.height);
	data->img.character_left.img = mlx_xpm_file_to_image(data->link, data->img.character_left.path, &data->img.character_left.width, &data->img.character_left.height);
	data->img.character_right.img = mlx_xpm_file_to_image(data->link, data->img.character_right.path, &data->img.character_right.width, &data->img.character_right.height);
	data->img.character_up.img = mlx_xpm_file_to_image(data->link, data->img.character_up.path, &data->img.character_up.width, &data->img.character_up.height);
	data->img.character_down.img = mlx_xpm_file_to_image(data->link, data->img.character_down.path, &data->img.character_down.width, &data->img.character_down.height);
	data->img.character1.img = mlx_xpm_file_to_image(data->link, data->img.character1.path, &data->img.character1.width, &data->img.character1.height);
	data->img.enemy.img = mlx_xpm_file_to_image(data->link, data->img.enemy.path, &data->img.enemy.width, &data->img.enemy.height);
	data->img.enemy1.img = mlx_xpm_file_to_image(data->link, data->img.enemy1.path, &data->img.enemy1.width, &data->img.enemy1.height);
	data->img.enemy2.img = mlx_xpm_file_to_image(data->link, data->img.enemy2.path, &data->img.enemy2.width, &data->img.enemy2.height);
	data->img.enemy3.img = mlx_xpm_file_to_image(data->link, data->img.enemy3.path, &data->img.enemy3.width, &data->img.enemy3.height);
	if (!data->img.floor.img)
		ft_printf("\nERROR loading floor image\n");

	if (!data->img.wall.img)
		ft_printf("\nERROR loading wall image\n");

	if (!data->img.item.img)
		ft_printf("\nERROR loading item image\n");

	if (!data->img.exit.img)
		ft_printf("\nERROR loading exit image\n");

	if (!data->img.character_left.img)
		ft_printf("\nERROR loading character_left image\n");

	if (!data->img.character_right.img)
		ft_printf("\nERROR loading character_right image\n");

	if (!data->img.character_up.img)
		ft_printf("\nERROR loading character_up image\n");

	if (!data->img.character_down.img)
		ft_printf("\nERROR loading character_down image\n");

	if (!data->img.character1.img)
		ft_printf("\nERROR loading character1 image\n");

	if (!data->img.enemy.img)
	ft_printf("\nERROR loading enemy image\n");

	if (!data->img.enemy1.img)
	ft_printf("\nERROR loading enemy1 image\n");

	if (!data->img.enemy2.img)
	ft_printf("\nERROR loading enemy2 image\n");

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
			if (data->map.map[data->map.y][data->map.x] == '0' || data->map.map[data->map.y][data->map.x] == 'T')
				mlx_put_image_to_window(data->link, data->screen, data->img.floor.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == '1')
				mlx_put_image_to_window(data->link, data->screen, data->img.wall.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'C')
				mlx_put_image_to_window(data->link, data->screen, data->img.item.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'E')
				mlx_put_image_to_window(data->link, data->screen, data->img.exit.img, data->img.x ,data->img.y);
			else if (data->map.map[data->map.y][data->map.x] == 'P')
				print_player(data);
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

// Print the player all direction or frame aimation
void	print_player(t_mlx_data *data)
{
	ft_printf("mouve = %d\n", data->player.last_move);
	if (data->player.img_frame == 1)
	{
		mlx_put_image_to_window(data->link, data->screen, data->img.character1.img, data->img.x ,data->img.y);
		data->player.img_frame = 0;
	}
	else if (data->player.img_frame == 0)
	{
		if (data->player.last_move == RIGHT)
			mlx_put_image_to_window(data->link, data->screen, data->img.character_right.img, data->img.x ,data->img.y);
		else if (data->player.last_move == LEFT)
			mlx_put_image_to_window(data->link, data->screen, data->img.character_left.img, data->img.x ,data->img.y);
		else if (data->player.last_move == UP)
			mlx_put_image_to_window(data->link, data->screen, data->img.character_up.img, data->img.x ,data->img.y);
		else if (data->player.last_move == DOWN)
			mlx_put_image_to_window(data->link, data->screen, data->img.character_down.img, data->img.x ,data->img.y);
		data->player.img_frame = 1;
	}
}

// taking all po of all entity
void	taking_pos(t_mlx_data *data)
{
	get_entity_pos(&data->map, PLAYER, 1);
	data->player.x = data->map.x;
	data->player.y = data->map.y;
	get_entity_pos(&data->map, BLINKY, 1);
	data->enemy.blinky.x = data->map.x;
	data->enemy.blinky.y = data->map.y;
	data->enemy.blinky.stash = '0';
	get_entity_pos(&data->map, PINKY, 1);
	data->enemy.pinky.x = data->map.x;
	data->enemy.pinky.y = data->map.y;
	data->enemy.pinky.stash = '0';
	get_entity_pos(&data->map, INKY, 1);
	data->enemy.inky.x = data->map.x;
	data->enemy.inky.y = data->map.y;
	data->enemy.inky.stash = '0';
	get_entity_pos(&data->map, CLYDE, 1);
	data->enemy.clyde.x = data->map.x;
	data->enemy.clyde.y = data->map.y;
	data->enemy.clyde.stash = '0';
}


int	main(int ac, char **av)
{
	srand(time(NULL));
	if (ac < 2)
		return (ft_printf("***MISSING ARGUMENT**\n./solong \"login42\"\n"), 1);
	t_mlx_data	data;
	data.current_frame = -100000;
	data.map.stach = '0';
	data.pseudo = av[1];
	data.player.last_move = 3;

	//Gestion map
	init_map(&data);
	taking_pos(&data);
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
