/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clyde_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:03:41 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/28 07:37:17 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Manage the mouvement of Clyde
char	**clyde_move(t_mlx_data *data, t_mlx_map *map)
{
	int		rdm;
	char	temp;

	get_entity_pos(map, CLYDE, 1);
	data->enemy.clyde.x = map->x;
	data->enemy.clyde.y = map->y;
	temp = data->enemy.clyde.stash;
	rdm = next_move(CLYDE, data);
	if (rdm == UP && !is_in_set(map->map[map->y - 1][map->x], "WXYZ1TtV"))
	{
		check_player_gameover(data, map, UP);
		map->stach = map->map[map->y - 1][map->x];
		map->map[map->y - 1][map->x] = CLYDE;
		map->map[map->y][map->x] = temp;
	}
	if (rdm == DOWN && !is_in_set(map->map[map->y + 1][map->x], "WXYZ1TtV"))
	{
		check_player_gameover(data, map, DOWN);
		map->stach = map->map[map->y + 1][map->x];
		map->map[map->y + 1][map->x] = CLYDE;
		map->map[map->y][map->x] = temp;
	}
	map->map = clyde_move_pt2(data, map, rdm, temp);
	data->enemy.clyde.last_move = rdm;
	return (map->map);
}

// Manage the mouvement of Clyde
char	**clyde_move_pt2(t_mlx_data *data, t_mlx_map *map, int rdm, char temp)
{
	if (rdm == LEFT && !is_in_set(map->map[map->y][map->x - 1], "WXYZ1TtV"))
	{
		check_player_gameover(data, map, LEFT);
		map->stach = map->map[map->y][map->x - 1];
		map->map[map->y][map->x - 1] = CLYDE;
		map->map[map->y][map->x] = temp;
	}
	if (rdm == RIGHT
		&& !is_in_set(map->map[map->y][map->x + 1], "WXYZ1TtV"))
	{
		check_player_gameover(data, map, RIGHT);
		map->stach = map->map[map->y][map->x + 1];
		map->map[map->y][map->x + 1] = CLYDE;
		map->map[map->y][map->x] = temp;
	}
	return (map->map);
}

// Get the next move of the enemy randomly
int	next_move(char entity, t_mlx_data *data)
{
	int	rdm;

	while (entity == CLYDE && rdm == data->enemy.clyde.last_move)
		rdm = (rand() % 4) + 1;
	data->enemy.clyde.last_move = rdm;
	return (rdm);
}
