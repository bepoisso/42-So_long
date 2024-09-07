/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:52 by bepoisso          #+#    #+#             */
/*   Updated: 2024/09/07 20:08:23 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**player_move(char **map, int move, int x, int y, int *item)
{
	if (move == UP && map[y - 1][x] != 1)
	{
		map[y - 1][x] = 'P';
		map[y][x] = '0';
	}
	else if (move == DOWN && map[y + 1][x] != 1)
	{
		map[y + 1][x] = 'P';
		map[y][x] = '0';
	}
	else if (move == LEFT && map[y][x + 1] != 1)
	{
		map[y][x + 1] = 'P';
		map[y][x] = '0';
	}
	else if (move == RIGHT && map[y][x - 1] != 1)
	{
		map[y][x - 1] = 'P';
		map[y][x] = '0';
	}
	return (map);
}
