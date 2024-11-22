/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleporter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:19 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/22 15:46:20 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_tp(char entity, t_mlx_map *map, int move)
{
	get_entity_pos(map, entity, 1);
	if (move == LEFT && map->map[map->y][map->x - 1] == 'T')
		return (touch_tp(entity, 'T', map), 1);
	else if (move == RIGHT && map->map[map->y][map->x + 1] == 't')
		return (touch_tp(entity, 't', map), 1);
	else
		return (0);
}

void	touch_tp(char entity, char which, t_mlx_map *map)
{
	int	x;
	int	y;

	get_entity_pos(map, entity, 1);
	x = map->x;
	y = map->y;
	if (which == 'T')
	{
		get_entity_pos(map, 't', 1);
		if (entity == 'P')
			map->map[y][x] = '0';
		else
			map->map[y][x] = map->stach;
		map->map[map->y][map->x - 1] = entity;
	}
	else
	{
		get_entity_pos(map, 'T', 1);
		if (entity == 'P')
			map->map[y][x] = '0';
		else
			map->map[y][x] = map->stach;
		map->map[map->y][map->x + 1] = entity;
	}
	get_entity_pos(map, 'P', 1);
}
