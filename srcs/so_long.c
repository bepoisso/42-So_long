/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/10/14 14:58:36 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy(data);
		exit(1);
	}
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

void	draw_background(t_mlx_data *data)
{
	t_mlx_img character;
	t_mlx_img background;
	int		x;
	int		y;
	character.path = "./srcs/character.xpm";
	background.path = "./srcs/floor.xpm";

	
	// Chargement de l'image
	background.img = mlx_xpm_file_to_image(data->link, background.path, &background.width, &background.height);
	if (!background.img)
		ft_printf("***ERROR BACKGROUND***\n\n");

	// Chargement de l'image
	character.img = mlx_xpm_file_to_image(data->link, character.path, &character.width, &character.height);
	if (!character.img)
		ft_printf("***ERROR CHARACTER***\n\n");

	// Affichage les images dans la fenêtre
	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			mlx_put_image_to_window(data->link, data->screen, background.img, x, y);
			
			x += 64;
		}
		y += 64;
	}
	mlx_put_image_to_window(data->link, data->screen, character.img, 256, 256);
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
	draw_background(&data);
	// Gestion des événements clavier
	mlx_key_hook(data.screen, handle_input, &data);
	mlx_loop(data.link);
}

