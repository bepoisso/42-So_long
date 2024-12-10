/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:41:48 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/10 17:39:54 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	ft_memset(&data, 0, sizeof(t_mlx_data));
	if (ac < 3)
		return (ft_perror("***MISSING ARGUMENT**\n./solong \"LOGIN_42\"\
 \"MAP\"\n", &data), 1);
	init_value(&data, av);
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
