/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pinky_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:53:10 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/28 07:56:46 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Pinky
// Trap the player

char	**pinky_move(t_mlx_data *data, t_mlx_map *map)
{
	char	temp;
	int		move;

	get_entity_pos(map, PINKY, 1);
	data->enemy.pinky.x = map->x;
	data->enemy.pinky.y = map->y;
	move = pinky_move_algo(data, &data->enemy.pinky, map);
	temp = data->enemy.pinky.stash;
	if (move == UP)
	{
		check_player_gameover(data, map, UP);
		data->enemy.pinky.stash
			= map->map[data->enemy.pinky.y - 1][data->enemy.pinky.x];
		map->map[data->enemy.pinky.y - 1][data->enemy.pinky.x] = PINKY;
		map->map[data->enemy.pinky.y][data->enemy.pinky.x] = temp;
	}
	if (move == DOWN)
	{
		check_player_gameover(data, map, DOWN);
		data->enemy.pinky.stash
			= map->map[data->enemy.pinky.y + 1][data->enemy.pinky.x];
		map->map[data->enemy.pinky.y + 1][data->enemy.pinky.x] = PINKY;
		map->map[data->enemy.pinky.y][data->enemy.pinky.x] = temp;
	}
	if (move == LEFT)
	{
		check_player_gameover(data, map, LEFT);
		data->enemy.pinky.stash
			= map->map[data->enemy.pinky.y][data->enemy.pinky.x - 1];
		map->map[data->enemy.pinky.y][data->enemy.pinky.x - 1] = PINKY;
		map->map[data->enemy.pinky.y][data->enemy.pinky.x] = temp;
	}
	if (move == RIGHT)
	{
		check_player_gameover(data, map, RIGHT);
		data->enemy.pinky.stash
			= map->map[data->enemy.pinky.y][data->enemy.pinky.x + 1];
		map->map[data->enemy.pinky.y][data->enemy.pinky.x + 1] = PINKY;
		map->map[data->enemy.pinky.y][data->enemy.pinky.x] = temp;
	}
	data->enemy.pinky.last_move = move;
	return (map->map);
}

int	pinky_move_algo(t_mlx_data *data, t_pinky *pinky, t_mlx_map *map)
{
	int	best_move;

	best_move = 0;
	pinky->calcu = 99999;
	if (pinky->last_move != DOWN
		&& !is_in_set(map->map[pinky->y - 1][pinky->x], "WXYZ1TtV"))
		best_move = pinky_best_move(data, best_move, UP);
	if (pinky->last_move != UP
		&& !is_in_set(map->map[pinky->y + 1][pinky->x], "WXYZ1TtV"))
		best_move = pinky_best_move(data, best_move, DOWN);
	if (pinky->last_move != RIGHT
		&& !is_in_set(map->map[pinky->y][pinky->x - 1], "WXYZ1TtV"))
		best_move = pinky_best_move(data, best_move, LEFT);
	if (pinky->last_move != LEFT
		&& !is_in_set(map->map[pinky->y][pinky->x + 1], "WXYZ1TtV"))
		best_move = pinky_best_move(data, best_move, RIGHT);
	return (best_move);
}

int	pinky_best_move(t_mlx_data *data, int best_move, int actual_move)
{
	int	result;
	int	target_x;
	int	target_y;

	target_x = data->player.x;
	target_y = data->player.y;
	if (data->player.last_move == UP)
		target_y -= 4;
	else if (data->player.last_move == DOWN)
		target_y += 4;
	else if (data->player.last_move == LEFT)
		target_x -= 4;
	else if (data->player.last_move == RIGHT)
		target_x += 4;
	if (actual_move == UP)
		result = abs((data->enemy.pinky.y - 1) - target_y)
			+ abs(data->enemy.pinky.x - target_x);
	else if (actual_move == DOWN)
		result = abs((data->enemy.pinky.y + 1) - target_y)
			+ abs(data->enemy.pinky.x - target_x);
	else if (actual_move == LEFT)
		result = abs(data->enemy.pinky.y - target_y)
			+ abs((data->enemy.pinky.x - 1) - target_x);
	else if (actual_move == RIGHT)
		result = abs(data->enemy.pinky.y - target_y)
			+ abs((data->enemy.pinky.x + 1) - target_x);
	if (result < data->enemy.pinky.calcu)
	{
		data->enemy.pinky.calcu = result;
		return (actual_move);
	}
	return (best_move);
}
