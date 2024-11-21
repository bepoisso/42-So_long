/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleporter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:19 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/21 17:59:33 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_tp(char entity, t_mlx_map *map, int move)
{
	if (move == LEFT && map->map[map->y][map->x - 1] == 'T')
		touch_tp(entity, 'T', map);
	else if (move == RIGHT && map->map[map->y][map->x + 1] == 't')
		touch_tp(entity, 't', map);
	else
		return;
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
