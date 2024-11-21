/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blinky_ai.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:58:19 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/21 22:30:14 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Blinky
// Follow Always the player
// 
// Pinky
// Trap the player
// 
// Incky
// Change direction wen following player
// 
// Clyde
// Random direction
// 

// Manage the mouvement of Blinky
char	**blinky_move(t_mlx_data *data, t_mlx_map *map)
{
	char	temp;
	int		move;

	move = blinky_move_algo(data, map);
	get_entity_pos(map, BLINKY, 1);
	if (move == UP)
	{
		check_player_gameover(data, map, UP);
		temp = data->enemy.blinky.stash;
		data->enemy.blinky.stash = map->map[data->enemy.blinky.y - 1][data->enemy.blinky.x];
		map->map[data->enemy.blinky.y - 1][data->enemy.blinky.x] = BLINKY;
		map->map[data->enemy.blinky.y][data->enemy.blinky.x] = temp;
	}
	if (move == DOWN)
	{
		check_player_gameover(data, map, DOWN);
		temp = data->enemy.blinky.stash;
		data->enemy.blinky.stash = map->map[data->enemy.blinky.y + 1][data->enemy.blinky.x];
		map->map[data->enemy.blinky.y + 1][data->enemy.blinky.x] = BLINKY;
		map->map[data->enemy.blinky.y][data->enemy.blinky.x] = temp;
	}
	if (move == LEFT)
	{
		check_player_gameover(data, map, LEFT);
		temp = data->enemy.blinky.stash;
		data->enemy.blinky.stash = map->map[data->enemy.blinky.y][data->enemy.blinky.x - 1];
		map->map[data->enemy.blinky.y][data->enemy.blinky.x - 1] = BLINKY;
		map->map[data->enemy.blinky.y][data->enemy.blinky.x] = temp;
	}
	if (move == RIGHT)
	{
		check_player_gameover(data, map, RIGHT);
		temp = data->enemy.blinky.stash;
		data->enemy.blinky.stash = map->map[data->enemy.blinky.y][data->enemy.blinky.x + 1];
		map->map[data->enemy.blinky.y][data->enemy.blinky.x + 1] = BLINKY;
		map->map[data->enemy.blinky.y][data->enemy.blinky.x] = temp;
		
	}
	data->enemy.blinky.last_move = move;
	ft_printf("%d\n", move);
	return (map->map);
}

int	blinky_move_algo(t_mlx_data *data, t_mlx_map *map)
{
	int	best_move = 0;
	data->enemy.blinky.calcu = 99999;

	get_entity_pos(map , BLINKY, 1);
	data->enemy.blinky.x = map->x;
	data->enemy.blinky.y = map->y;
	get_entity_pos(map , 'P', 1);
	if (data->enemy.blinky.last_move != UP && !is_in_set(map->map[data->enemy.blinky.y - 1][data->enemy.blinky.x], "WXYZ1Tt"))
		best_move = blinky_best_move(data, best_move, UP);
	if (data->enemy.blinky.last_move != DOWN && !is_in_set(map->map[data->enemy.blinky.y + 1][data->enemy.blinky.x], "WXYZ1Tt"))
		best_move = blinky_best_move(data, best_move, DOWN);
	if (data->enemy.blinky.last_move != LEFT && !is_in_set(map->map[data->enemy.blinky.y][data->enemy.blinky.x - 1], "WXYZ1Tt"))
		best_move = blinky_best_move(data, best_move, LEFT);
	if (data->enemy.blinky.last_move != RIGHT && !is_in_set(map->map[data->enemy.blinky.y][data->enemy.blinky.x + 1], "WXYZ1Tt"))
		best_move = blinky_best_move(data, best_move, RIGHT);
	return (best_move);
}

int	blinky_best_move(t_mlx_data *data, int best_move, int actual_move)
{
	int	result;

	result = abs(data->enemy.blinky.y - data->map.y) + abs(data->enemy.blinky.x - data->map.x);
	if (result < data->enemy.blinky.calcu)
	{
		data->enemy.blinky.calcu = result;
		ft_printf("Actuel = %d for %d\n", actual_move, result);
		return (actual_move);
	}
	ft_printf("Actuel = %d for %d\n", best_move, result);
	return (best_move);
}
