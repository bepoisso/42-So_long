/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clyde_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:03:41 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/22 16:05:43 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Manage the mouvement of Clyde
char	**clyde_move(t_mlx_data *data, t_mlx_map *map)
{
	int		rdm;
	int		i;
	char	temp;
	char	type;

	get_entity_pos(map, CLYDE, 1);
	data->enemy.clyde.x = map->x;
	data->enemy.clyde.y = map->y;
	type = CLYDE;
	i = 0;
	rdm = next_move(CLYDE, data);
	while (i < 10)
	{
		i++;
		rdm = next_move(type, data);
		if (rdm == UP && !is_in_set(map->map[map->y - 1][map->x], "WXYZ1TtV"))
		{
			check_player_gameover(data, map, UP);
			temp = map->stach;
			map->stach = map->map[map->y - 1][map->x];
			map->map[map->y - 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == DOWN && !is_in_set(map->map[map->y + 1][map->x], "WXYZ1TtV"))
		{
			check_player_gameover(data, map, DOWN);
			temp = map->stach;
			map->stach = map->map[map->y + 1][map->x];
			map->map[map->y + 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == LEFT && !is_in_set(map->map[map->y][map->x - 1], "WXYZ1TtV"))
		{
			check_player_gameover(data, map, LEFT);
			temp = map->stach;
			map->stach = map->map[map->y][map->x - 1];
			map->map[map->y][map->x - 1] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == RIGHT && !is_in_set(map->map[map->y][map->x + 1], "WXYZ1TtV"))
		{
			check_player_gameover(data, map, RIGHT);
			temp = map->stach;
			map->stach = map->map[map->y][map->x + 1];
			map->map[map->y][map->x + 1] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
	}
	data->enemy.clyde.last_move = rdm + pow(-1, rdm + 1);
	return (map->map);
}

// Get the next move of the enemy randomly
int	next_move(char entity, t_mlx_data *data)
{
	int	rdm;

	rdm = (rand()% 4) + 1;
	while (entity == BLINKY && rdm == data->enemy.blinky.last_move)
		rdm = (rand() % 4) + 1;
	while (entity == INKY && rdm == data->enemy.inky.last_move)
		rdm = (rand() % 4) + 1;
	while (entity == PINKY && rdm == data->enemy.pinky.last_move)
		rdm = (rand() % 4) + 1;
	while (entity == CLYDE && rdm == data->enemy.clyde.last_move)
		rdm = (rand() % 4) + 1;
	return (rdm);
}
