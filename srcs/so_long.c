/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/31 17:09:48 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	deal_key(int key, void *param)
{
	write(1, "PRESS\n", 6);
	return (0);
}

int	main(void)
{
	void	*ptr_mlx;
	void	*ptr_window;

	ptr_mlx = mlx_init();
	ptr_window = mlx_new_window(ptr_mlx, 500, 500, "So_long");
	mlx_pixel_put(ptr_mlx, ptr_window, 250, 250, 255 + 255 + 255);
	mlx_key_hook(ptr_window, &deal_key, NULL);
	mlx_loop(ptr_mlx);
}
