/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:52 by bepoisso          #+#    #+#             */
/*   Updated: 2024/09/02 22:03:58 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char **player_move(char **map, int move, int x, int y)
{
	if (move == UP)
	{
		if (map[y - 1][x] != 1)
		{
			map[y - 1][x] = 'P';
			map[y][x] = '0';
		}
	}
	else if (move == DOWN)
	{
		if (map[y + 1][x] != 1)
		{
			map[y + 1][x] = 'P';
			map[y][x] = '0';
		}
	}
	else if (move == LEFT)
	{
		if (map[y][x + 1] != 1)
		{
			map[y][x + 1] = 'P';
			map[y][x] = '0';
		}
	}
	else if (move == RIGHT)
	{
		if (map[y][x - 1] != 1)
		{
			map[y][x - 1] = 'P';
			map[y][x] = '0';
		}
	}
	return (map);
}
