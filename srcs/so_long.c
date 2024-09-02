/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:01:39 by bepoisso          #+#    #+#             */
/*   Updated: 2024/09/02 15:41:46 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_void(void)
{
	ft_putchar_fd('X', 1);
	return (1);
}

int	main(void)
{
	t_mlx_data	data;

	data.link = mlx_init();
	data.screen = mlx_new_window(data.link, 500, 500, "So_long");
	mlx_key_hook(data.screen, &ft_void, (void *)NULL);
	mlx_loop(data.link);
}
