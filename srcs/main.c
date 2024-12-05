/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:41:48 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/04 16:06:16 by bepoisso         ###   ########.fr       */
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
	if (keysym == XK_KP_Enter)
	{
		mlx_loop_end(data->link);
	}
	return (0);
}

int	init_help(t_help *help)
{
	help->link = mlx_init();
	
}

int	main(int ac, char **av)
{
	t_mlx_data	data;

	ft_memset(&data, 0, sizeof(t_mlx_data));
	init_value(&data, av);
	if (ac < 2)
		return (ft_perror("***MISSING ARGUMENT**\n./solong \"login42\"\n",
				&data), 1);
	data.link = mlx_init();
	if (!data.link)
		ft_perror("***ERROR MLX_INIT***\n\n", &data);
	data.screen = mlx_new_window(data.link, TEXTUR_SIZE * data.map.x_max,
			TEXTUR_SIZE * (data.map.y_max + 2), "PACMAN");
	data.help.screen = mlx_new_window(data.link, 500, 500, "HELP");
	if (!data.screen || !data.help.screen)
		ft_perror("***ERROR SCREEN***\n\n", &data);
	mlx_key_hook(data.help.screen, key_help, &data);
	init_img(&data);
	mlx_put_image_to_window(data.link, data.help.screen, data.help.img.img,
		0, 0);
	mlx_hook(data.screen, DestroyNotify, NoEventMask, mlx_destroy, &data);
	print_map(&data);
	mlx_loop(data.link);
	mlx_key_hook(data.screen, handle_input, &data);
	mlx_loop_hook(data.link, update_frame, &data);
	mlx_loop(data.link);
}
