/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/04 07:33:46 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Taking information if a key pressed and transfert to the right function
int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape) // CLOSE ON ESC
	{
		mlx_destroy(data);
		exit(0);
	}
	if (keysym == 119 && keysym == 65362) // UP 119 - 122
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, UP);
		data->player.last_move = UP;
		print_map(data);
	}
	if (keysym == 97 && keysym == 65361) // LEFT 97 - 113
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, LEFT);
		data->player.last_move = LEFT;
		print_map(data);
	}
	if (keysym == 115 && keysym == 65364) // DOWN 115
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, DOWN);
		data->player.last_move = DOWN;
		print_map(data);
	}
	if (keysym == 100 && keysym == 65363) // RIGHT 100
	{
		mlx_clear_window(data->link, data->screen);
		data->map.map = player_move(data, &data->map, RIGHT);
		data->player.last_move = RIGHT;
		print_map(data);
	}
	ft_printf("\nMouvement counter = %d\n", data->map.move_count);
	ft_printf("keysym = %d\n", keysym);
	data->temp = ft_itoa(data->map.move_count);
	mlx_string_put(data->link, data->screen, 0, TEXTUR_SIZE * (data->map.y_max + 2), encode_trgb(0, 255, 255, 255), "Mouvement count : ");
	mlx_string_put(data->link, data->screen, 110, TEXTUR_SIZE * (data->map.y_max + 2), encode_trgb(0, 255, 255, 255), data->temp);
	free(data->temp);
	data->temp = ft_itoa(data->map.item);
	mlx_string_put(data->link, data->screen, 0, TEXTUR_SIZE * (data->map.y_max + 1) + 10, encode_trgb(0, 255, 255, 255), "Item count : ");
	mlx_string_put(data->link, data->screen, 110, TEXTUR_SIZE * (data->map.y_max + 1) + 10, encode_trgb(0, 255, 255, 255), data->temp);
	free(data->temp);
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
	data->img.exit1.path = "./imgs/exit1.xpm";
	data->img.character_left.path = "./imgs/character_left.xpm";
	data->img.character_right.path = "./imgs/character_right.xpm";
	data->img.character_up.path = "./imgs/character_up.xpm";
	data->img.character_down.path = "./imgs/character_down.xpm";
	data->img.character1.path = "./imgs/character1.xpm";
	data->img.blinky.path = "./imgs/blinky_up.xpm";
	data->img.blinky.path_down = "./imgs/blinky_down.xpm";
	data->img.blinky.path_left = "./imgs/blinky_left.xpm";
	data->img.blinky.path_right = "./imgs/blinky_right.xpm";
	data->img.pinky.path = "./imgs/pinky_up.xpm";
	data->img.pinky.path_down = "./imgs/pinky_down.xpm";
	data->img.pinky.path_left = "./imgs/pinky_left.xpm";
	data->img.pinky.path_right = "./imgs/pinky_right.xpm";
	data->img.inky.path = "./imgs/inky_up.xpm";
	data->img.inky.path_down = "./imgs/inky_down.xpm";
	data->img.inky.path_left = "./imgs/inky_left.xpm";
	data->img.inky.path_right = "./imgs/inky_right.xpm";
	data->img.clyde.path = "./imgs/clyde_up.xpm";
	data->img.clyde.path_down = "./imgs/clyde_down.xpm";
	data->img.clyde.path_left = "./imgs/clyde_left.xpm";
	data->img.clyde.path_right = "./imgs/clyde_right.xpm";
	data->help.img.path = "./imgs/help_page.xpm";
	data->help.img.img = mlx_xpm_file_to_image(data->link, data->help.img.path, &data->help.img.width, &data->help.img.height);
	data->img.floor.img = mlx_xpm_file_to_image(data->link, data->img.floor.path, &data->img.floor.width, &data->img.floor.height);
	data->img.wall.img = mlx_xpm_file_to_image(data->link, data->img.wall.path, &data->img.wall.width, &data->img.wall.height);
	data->img.item.img = mlx_xpm_file_to_image(data->link, data->img.item.path, &data->img.item.width, &data->img.item.height);
	data->img.exit.img = mlx_xpm_file_to_image(data->link, data->img.exit.path, &data->img.exit.width, &data->img.exit.height);
	data->img.exit1.img = mlx_xpm_file_to_image(data->link, data->img.exit1.path, &data->img.exit1.width, &data->img.exit1.height);
	data->img.character_left.img = mlx_xpm_file_to_image(data->link, data->img.character_left.path, &data->img.character_left.width, &data->img.character_left.height);
	data->img.character_right.img = mlx_xpm_file_to_image(data->link, data->img.character_right.path, &data->img.character_right.width, &data->img.character_right.height);
	data->img.character_up.img = mlx_xpm_file_to_image(data->link, data->img.character_up.path, &data->img.character_up.width, &data->img.character_up.height);
	data->img.character_down.img = mlx_xpm_file_to_image(data->link, data->img.character_down.path, &data->img.character_down.width, &data->img.character_down.height);
	data->img.character1.img = mlx_xpm_file_to_image(data->link, data->img.character1.path, &data->img.character1.width, &data->img.character1.height);
	data->img.blinky.img = mlx_xpm_file_to_image(data->link, data->img.blinky.path, &data->img.blinky.width, &data->img.blinky.height);
	data->img.blinky.img_down = mlx_xpm_file_to_image(data->link, data->img.blinky.path_down, &data->img.blinky.width, &data->img.blinky.height);
	data->img.blinky.img_left = mlx_xpm_file_to_image(data->link, data->img.blinky.path_left, &data->img.blinky.width, &data->img.blinky.height);
	data->img.blinky.img_right = mlx_xpm_file_to_image(data->link, data->img.blinky.path_right, &data->img.blinky.width, &data->img.blinky.height);
	data->img.pinky.img = mlx_xpm_file_to_image(data->link, data->img.pinky.path, &data->img.pinky.width, &data->img.pinky.height);
	data->img.pinky.img_down = mlx_xpm_file_to_image(data->link, data->img.pinky.path_down, &data->img.pinky.width, &data->img.pinky.height);
	data->img.pinky.img_left = mlx_xpm_file_to_image(data->link, data->img.pinky.path_left, &data->img.pinky.width, &data->img.pinky.height);
	data->img.pinky.img_right = mlx_xpm_file_to_image(data->link, data->img.pinky.path_right, &data->img.pinky.width, &data->img.pinky.height);
	data->img.inky.img = mlx_xpm_file_to_image(data->link, data->img.inky.path, &data->img.inky.width, &data->img.inky.height);
	data->img.inky.img_down = mlx_xpm_file_to_image(data->link, data->img.inky.path_down, &data->img.inky.width, &data->img.inky.height);
	data->img.inky.img_left = mlx_xpm_file_to_image(data->link, data->img.inky.path_left, &data->img.inky.width, &data->img.inky.height);
	data->img.inky.img_right = mlx_xpm_file_to_image(data->link, data->img.inky.path_right, &data->img.inky.width, &data->img.inky.height);
	data->img.clyde.img = mlx_xpm_file_to_image(data->link, data->img.clyde.path, &data->img.clyde.width, &data->img.clyde.height);
	data->img.clyde.img_down = mlx_xpm_file_to_image(data->link, data->img.clyde.path_down, &data->img.clyde.width, &data->img.clyde.height);
	data->img.clyde.img_left = mlx_xpm_file_to_image(data->link, data->img.clyde.path_left, &data->img.clyde.width, &data->img.clyde.height);
	data->img.clyde.img_right = mlx_xpm_file_to_image(data->link, data->img.clyde.path_right, &data->img.clyde.width, &data->img.clyde.height);
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
	if (!data->img.character1.img)
		ft_perror("\nERROR loading character1 image\n", data);
	if (!data->img.blinky.img || !data->img.blinky.img_down || !data->img.blinky.img_left || !data->img.blinky.img_right)
		ft_perror("\nERROR loading clyde image\n", data);
	if (!data->img.pinky.img || !data->img.pinky.img_down || !data->img.pinky.img_left || !data->img.pinky.img_right)
		ft_perror("\nERROR loading pinky image\n", data);
	if (!data->img.inky.img || !data->img.inky.img_down || !data->img.inky.img_left || !data->img.inky.img_right)
		ft_perror("\nERROR loading inky image\n", data);
	if (!data->img.clyde.img || !data->img.clyde.img_down || !data->img.clyde.img_left || !data->img.clyde.img_right)
		ft_perror("\nERROR loading clyde image\n", data);
	if (!data->help.img.img)
		ft_perror("\nERROR loading Help_page image\n", data);
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
			{
				if (data->map.item != 0)
					mlx_put_image_to_window(data->link, data->screen, data->img.exit.img, data->img.x ,data->img.y);
				else
					mlx_put_image_to_window(data->link, data->screen, data->img.exit1.img, data->img.x ,data->img.y);

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
			data->map.x++;
			data->img.x += TEXTUR_SIZE;
		}
		data->map.y++;
		data->img.y += TEXTUR_SIZE;
	}
}

void	print_clyde(t_mlx_data *data)
{
	if (data->enemy.clyde.last_move == UP)
	mlx_put_image_to_window(data->link, data->screen, data->img.clyde.img, data->img.x, data->img.y);
	else if (data->enemy.clyde.last_move == DOWN)
	mlx_put_image_to_window(data->link, data->screen, data->img.clyde.img_down, data->img.x, data->img.y);
	else if (data->enemy.clyde.last_move == LEFT)
	mlx_put_image_to_window(data->link, data->screen, data->img.clyde.img_left, data->img.x, data->img.y);
	else
	mlx_put_image_to_window(data->link, data->screen, data->img.clyde.img_right, data->img.x, data->img.y);
}

void	print_inky(t_mlx_data *data)
{
	if (data->enemy.inky.last_move == UP)
	mlx_put_image_to_window(data->link, data->screen, data->img.inky.img, data->img.x, data->img.y);
	else if (data->enemy.inky.last_move == DOWN)
	mlx_put_image_to_window(data->link, data->screen, data->img.inky.img_down, data->img.x, data->img.y);
	else if (data->enemy.inky.last_move == LEFT)
	mlx_put_image_to_window(data->link, data->screen, data->img.inky.img_left, data->img.x, data->img.y);
	else
	mlx_put_image_to_window(data->link, data->screen, data->img.inky.img_right, data->img.x, data->img.y);
}

void	print_pinky(t_mlx_data *data)
{
	if (data->enemy.pinky.last_move == UP)
	mlx_put_image_to_window(data->link, data->screen, data->img.pinky.img, data->img.x, data->img.y);
	else if (data->enemy.pinky.last_move == DOWN)
	mlx_put_image_to_window(data->link, data->screen, data->img.pinky.img_down, data->img.x, data->img.y);
	else if (data->enemy.pinky.last_move == LEFT)
	mlx_put_image_to_window(data->link, data->screen, data->img.pinky.img_left, data->img.x, data->img.y);
	else
	mlx_put_image_to_window(data->link, data->screen, data->img.pinky.img_right, data->img.x, data->img.y);
}

void	print_blinky(t_mlx_data *data)
{
	if (data->enemy.blinky.last_move == UP)
	mlx_put_image_to_window(data->link, data->screen, data->img.blinky.img, data->img.x, data->img.y);
	else if (data->enemy.blinky.last_move == DOWN)
	mlx_put_image_to_window(data->link, data->screen, data->img.blinky.img_down, data->img.x, data->img.y);
	else if (data->enemy.blinky.last_move == LEFT)
	mlx_put_image_to_window(data->link, data->screen, data->img.blinky.img_left, data->img.x, data->img.y);
	else
	mlx_put_image_to_window(data->link, data->screen, data->img.blinky.img_right, data->img.x, data->img.y);
}

// Print the player all direction or frame aimation
void	print_player(t_mlx_data *data)
{
	if (data->player.img_frame >= 1)
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

void	ft_perror(char *str, t_mlx_data *data)
{
	ft_putstr_fd(str, 1);
	data->status = 1;
	mlx_destroy(data);
}


int	main(int ac, char **av)
{
	t_mlx_data	data;

	ft_memset(&data, 0, sizeof(t_mlx_data));
	data.status = 0;
	srand(time(NULL));
	if (ac < 2)
		return (ft_perror("***MISSING ARGUMENT**\n./solong \"login42\"\n", &data), 1);
	data.current_frame = -100000;
	data.map.stach = '0';
	data.pseudo = av[1];
	data.player.last_move = 3;

	//Gestion map
	init_map(&data);
	taking_pos(&data);
	data.link = mlx_init();
	if (!data.link)
		ft_perror("***ERROR MLX_INIT***\n\n", &data);

	data.screen = mlx_new_window(data.link, TEXTUR_SIZE * data.map.x_max, TEXTUR_SIZE * (data.map.y_max + 2), "PACMAN");
	data.help.screen = mlx_new_window(data.link, 500, 500, "HELP");
	if (!data.screen || !data.help.screen)
		ft_perror("***ERROR SCREEN***\n\n", &data);

	// Gestions des la croix (X)
	mlx_hook(data.screen, DestroyNotify, NoEventMask, mlx_destroy, &data);

	//Gestion de l'impression tableau
	init_img(&data);
	mlx_put_image_to_window(data.link, data.help.screen, data.help.img.img, 0, 0);
	print_map(&data);
	
	
	
	// Gestion des événements clavier
	mlx_key_hook(data.screen, handle_input, &data);
	mlx_loop_hook(data.link, update_frame, &data);
	mlx_loop(data.link);
}
