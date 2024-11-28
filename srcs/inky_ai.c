/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inky_ai.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:58:21 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/28 10:25:17 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Manage the mouvement of Blinky
char	**inky_move(t_mlx_data *data, t_mlx_map *map)
{
	char	temp;
	int		move;

	move = inky_move_algo(data, map);
	temp = data->enemy.inky.stash;
	get_entity_pos(map, INKY, 1);
	if (move == UP)
	{
		check_player_gameover(data, map, UP);
		data->enemy.inky.stash
			= map->map[data->enemy.inky.y - 1][data->enemy.inky.x];
		map->map[data->enemy.inky.y - 1][data->enemy.inky.x] = INKY;
		map->map[data->enemy.inky.y][data->enemy.inky.x] = temp;
	}
	if (move == DOWN)
	{
		check_player_gameover(data, map, DOWN);
		data->enemy.inky.stash
			= map->map[data->enemy.inky.y + 1][data->enemy.inky.x];
		map->map[data->enemy.inky.y + 1][data->enemy.inky.x] = INKY;
		map->map[data->enemy.inky.y][data->enemy.inky.x] = temp;
	}
	inky_move_pt2(data, map, move, temp);
	data->enemy.inky.last_move = move;
	return (map->map);
}

char	**inky_move_pt2(t_mlx_data *data, t_mlx_map *map, int move, char temp)
{
	if (move == LEFT)
	{
		check_player_gameover(data, map, LEFT);
		data->enemy.inky.stash
			= map->map[data->enemy.inky.y][data->enemy.inky.x - 1];
		map->map[data->enemy.inky.y][data->enemy.inky.x - 1] = INKY;
		map->map[data->enemy.inky.y][data->enemy.inky.x] = temp;
	}
	if (move == RIGHT)
	{
		check_player_gameover(data, map, RIGHT);
		data->enemy.inky.stash
			= map->map[data->enemy.inky.y][data->enemy.inky.x + 1];
		map->map[data->enemy.inky.y][data->enemy.inky.x + 1] = INKY;
		map->map[data->enemy.inky.y][data->enemy.inky.x] = temp;
	}
	return (map->map);
}

// Restrict the inky movement to dont go back
int	inky_move_algo(t_mlx_data *data, t_mlx_map *map)
{
	int	best_move;

	best_move = 0;
	data->enemy.inky.calcu = -1;
	get_entity_pos(map, INKY, 1);
	data->enemy.inky.x = map->x;
	data->enemy.inky.y = map->y;
	if (data->enemy.inky.last_move != DOWN
		&& !is_in_set(map->map[data->enemy.inky.y - 1][data->enemy.inky.x]
		, "WXYZ1TtV"))
		best_move = inky_best_move(data, best_move, UP);
	if (data->enemy.inky.last_move != UP
		&& !is_in_set(map->map[data->enemy.inky.y + 1][data->enemy.inky.x]
		, "WXYZ1TtV"))
		best_move = inky_best_move(data, best_move, DOWN);
	if (data->enemy.inky.last_move != RIGHT
		&& !is_in_set(map->map[data->enemy.inky.y][data->enemy.inky.x - 1]
		, "WXYZ1TtV"))
		best_move = inky_best_move(data, best_move, LEFT);
	if (data->enemy.inky.last_move != LEFT
		&& !is_in_set(map->map[data->enemy.inky.y][data->enemy.inky.x + 1]
		, "WXYZ1TtV"))
		best_move = inky_best_move(data, best_move, RIGHT);
	return (best_move);
}

// Compare the best move with the actual move using the manhattan distance
int	inky_best_move(t_mlx_data *data, int best_move, int actual_move)
{
	int	result;
	int	player_x;
	int	player_y;

	get_entity_pos(&data->map, 'P', 1);
	player_x = data->map.x;
	player_y = data->map.y;
	if (actual_move == UP)
		result = abs((data->enemy.inky.y - 1) - player_y)
			+ abs(data->enemy.inky.x - player_x);
	else if (actual_move == DOWN)
		result = abs((data->enemy.inky.y + 1) - player_y)
			+ abs(data->enemy.inky.x - player_x);
	else if (actual_move == LEFT)
		result = abs(data->enemy.inky.y - player_y)
			+ abs((data->enemy.inky.x - 1) - player_x);
	else if (actual_move == RIGHT)
		result = abs(data->enemy.inky.y - player_y)
			+ abs((data->enemy.inky.x + 1) - player_x);
	if (result > data->enemy.inky.calcu)
	{
		data->enemy.inky.calcu = result;
		return (actual_move);
	}
	return (best_move);
}
