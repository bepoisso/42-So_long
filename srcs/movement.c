/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:52 by bepoisso          #+#    #+#             */
/*   Updated: 2024/09/08 12:29:35 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**player_move(t_manip_map *map, int move)
{
	if (move == UP && map->map[map->y - 1][map->x] != '1')
	{
		map->item += check_item_counter(map, move);
		map->map[map->y - 1][map->x] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == DOWN && map->map[map->y + 1][map->x] != '1')
	{
		map->item += check_item_counter(map, move);
		map->map[map->y + 1][map->x] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == LEFT && map->map[map->y][map->x + 1] != '1')
	{
		map->item += check_item_counter(map, move);
		map->map[map->y][map->x + 1] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == RIGHT && map->map[map->y][map->x - 1] != '1')
	{
		map->item += check_item_counter(map, move);
		map->map[map->y][map->x - 1] = 'P';
		map->map[map->y][map->x] = '0';
	}
	return (map);
}

int	check_item_counter(t_manip_map *map, int move)
{
	int	count;

	count = 0;
	if (move == UP && map->map[map->y - 1][map->x] == 'C')
		count++;
	else if (move == DOWN && map->map[map->y + 1][map->x] != 'C')
		count++;
	else if (move == LEFT && map->map[map->y][map->x + 1] != 'C')
		count++;
	else if (move == RIGHT && map->map[map->y][map->x - 1] != 'C')
		count++;
	return (count);
}
