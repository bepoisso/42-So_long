/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoreboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:20:47 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/19 15:26:35 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_in_scoreboard(t_mlx_data *data)
{
	int	fd;

	fd = open("./srcs/pacman.sb", O_APPEND | O_WRONLY);
	if (fd == -1)
		return ((void)ft_printf("***FAIL TO ADD IN SCOREBOARD***"));
	ft_putstr_fd(data->pseudo, fd);
	ft_putstr_fd(":", fd);
	ft_putnbr_fd(data->map.move_count, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	create_scoreboard("./srcs/pacman.sb", data)
}

void	create_scoreboard(char *path, t_mlx_data *data)
{
	
}
