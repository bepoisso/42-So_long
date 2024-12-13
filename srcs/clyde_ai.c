/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clyde_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:03:41 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/13 12:06:01 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// NEED TO BE FIXED (CHECK IF A WAL IS IN THE WAY BEFORE SET RDM)
// Manage the mouvement of Clyde
char	**clyde_move(t_mlx_data *data, t_mlx_map *map)
{
	int		rdm;
	char	temp;

	get_entity_pos(map, CLYDE, 1);
	data->enemy.clyde.x = map->x;
	data->enemy.clyde.y = map->y;
	temp = data->enemy.clyde.stash;
	rdm = next_move(data, map);
	if (rdm == UP && !is_in_set(map->map[map->y - 1][map->x], "WXYZ1TtV"))
	{
		check_player_gameover(data, map, UP);
		data->enemy.clyde.stash = map->map[map->y - 1][map->x];
		map->map[map->y - 1][map->x] = CLYDE;
		map->map[map->y][map->x] = temp;
	}
		if (rdm == DOWN && !is_in_set(map->map[map->y + 1][map->x], "WXYZ1TtV"))
	{
		check_player_gameover(data, map, DOWN);
		data->enemy.clyde.stash = map->map[map->y + 1][map->x];
		map->map[map->y + 1][map->x] = CLYDE;
		map->map[map->y][map->x] = temp;
	}
	map->map = clyde_move_pt2(data, map, rdm, temp);
	get_last_move(data, rdm);
	return (map->map);
}

void	get_last_move(t_mlx_data *data, int move)
{
	if (move == UP)
		data->enemy.clyde.last_move = DOWN;
	if (move == DOWN)
		data->enemy.clyde.last_move = UP;
	if (move == LEFT)
		data->enemy.clyde.last_move = RIGHT;
	if (move == RIGHT)
		data->enemy.clyde.last_move = LEFT;
}

// Manage the mouvement of Clyde
char	**clyde_move_pt2(t_mlx_data *data, t_mlx_map *map, int rdm, char temp)
{
	if (rdm == LEFT && !is_in_set(map->map[map->y][map->x - 1], "WXYZ1TtV"))
	{
		check_player_gameover(data, map, LEFT);
		data->enemy.clyde.stash = map->map[map->y][map->x - 1];
		map->map[map->y][map->x - 1] = CLYDE;
		map->map[map->y][map->x] = temp;
	}
	if (rdm == RIGHT
		&& !is_in_set(map->map[map->y][map->x + 1], "WXYZ1TtV"))
	{
		check_player_gameover(data, map, RIGHT);
		data->enemy.clyde.stash = map->map[map->y][map->x + 1];
		map->map[map->y][map->x + 1] = CLYDE;
		map->map[map->y][map->x] = temp;
	}
	return (map->map);
}

// Get the next move of the enemy randomly
int	next_move(t_mlx_data *data, t_mlx_map *map)
{
	int	rdm;
	int	check;

	check = 1;
	while (check != 0 && check <= 100)
	{
		check++;
		rdm = (rand() % 4) + 1;
		if (rdm == UP && !is_in_set(map->map[map->y - 1][map->x], "WXYZ1V") && rdm != data->enemy.clyde.last_move)
			return (rdm);
		else if (rdm == DOWN && !is_in_set(map->map[map->y + 1][map->x], "WXYZ1V") && rdm != data->enemy.clyde.last_move)
			return (rdm);
		else if (rdm == LEFT && !is_in_set(map->map[map->y][map->x - 1], "WXYZ1V") && rdm != data->enemy.clyde.last_move)
			return (rdm);
		else if (rdm == RIGHT && !is_in_set(map->map[map->y][map->x + 1], "WXYZ1V") && rdm != data->enemy.clyde.last_move)
			return (rdm);
	}
	return (0);
}
