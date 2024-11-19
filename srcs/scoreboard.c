/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoreboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:20:47 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/19 13:48:57 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_in_scoreboard(t_mlx_data *data)
{
	char	fd;

	fd = open("./srcs/pacman.sb", O_APPEND | O_WRONLY);
	if (fd == -1)
		return ((void)ft_printf("***FAIL TO ADD IN SCOREBOARD***"));
	ft_putnbr_fd(data->map.move_count, fd);
	ft_putstr_fd(" -> ", fd);
	ft_putendl_fd(data->pseudo, fd);
	// aff_fd(fd);
	close(fd);
}

/* void	aff_fd(int fd)
{
	char	buf[1];
	char	readed;

	readed = 1;
	while (readed != 0)
	{
		readed = read(fd, buf, 1);
		ft_putchar(readed);
	}
} */
