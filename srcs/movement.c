/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:52 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/08 12:38:45 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Taking the position of player and
// Check where the player want to go and if it's possible
// 
// Check if the player hit a enemy or collect a item
// 
// Then check if the player as finish by hiting the exit
char	**player_move(t_mlx_data *data, t_mlx_map *map, int move)
{
	get_entity_pos(map, PLAYER, 1);
	data->player.x = map->x;
	data->player.y = map->y;
	if (move == UP && map->map[data->player.y - 1][data->player.x] != '1')
	{
		data->player.move_count++;
		check_item_counter(data, map, move);
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		map->map[data->player.y - 1][data->player.x] = 'P';
		map->map[data->player.y][data->player.x] = '0';
	}
	else if (move == DOWN
		&& map->map[data->player.y + 1][data->player.x] != '1')
	{
		map->move_count++;
		check_item_counter(data, map, move);
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		map->map[data->player.y + 1][data->player.x] = 'P';
		map->map[data->player.y][data->player.x] = '0';
	}
	map->map = player_move_pt2(data, map, move);
	return (map->map);
}

char	**player_move_pt2(t_mlx_data *data, t_mlx_map *map, int move)
{
	if (move == LEFT && map->map[data->player.y][data->player.x - 1] != '1')
	{
		map->move_count++;
		check_item_counter(data, map, move);
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		if (check_tp('P', map, LEFT))
			return (map->map);
		map->map[data->player.y][data->player.x - 1] = 'P';
		map->map[data->player.y][data->player.x] = '0';
	}
	else if (move == RIGHT
		&& map->map[data->player.y][data->player.x + 1] != '1')
	{
		map->move_count++;
		check_item_counter(data, map, move);
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		if (check_tp('P', map, RIGHT))
			return (map->map);
		map->map[data->player.y][data->player.x + 1] = 'P';
		map->map[data->player.y][data->player.x] = '0';
	}
	return (map->map);
}

// Check if the player taking a items and decramante the counter
void	check_item_counter(t_mlx_data *data, t_mlx_map *map, int move)
{
	if (move == UP && map->map[data->player.y - 1][data->player.x] == 'C')
		map->item--;
	else if (move == DOWN
		&& map->map[data->player.y + 1][data->player.x] == 'C')
		map->item--;
	else if (move == LEFT
		&& map->map[data->player.y][data->player.x - 1] == 'C')
		map->item--;
	else if (move == RIGHT
		&& map->map[data->player.y][data->player.x + 1] == 'C')
		map->item--;
}

// Check if the player want to exit and if hi have all the items
// if it is adding the score on scorebord or game over
void	check_end(t_mlx_data *data, t_mlx_map *map, int move)
{
	if (map->item == 0)
	{
		if (move == UP && map->map[data->player.y - 1][data->player.x] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			save_in_scoreboard(data);
			mlx_destroy(data);
		}
		else if (move == DOWN
			&& map->map[data->player.y + 1][data->player.x] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			save_in_scoreboard(data);
			mlx_destroy(data);
		}
		else if (move == LEFT
			&& map->map[data->player.y][data->player.x - 1] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			save_in_scoreboard(data);
			mlx_destroy(data);
		}
	}
	check_end_pt2(data, map, move);
}

void	check_end_pt2(t_mlx_data *data, t_mlx_map *map, int move)
{
	if (map->item == 0)
	{
		if (move == RIGHT
			&& map->map[data->player.y][data->player.x + 1] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			save_in_scoreboard(data);
			mlx_destroy(data);
		}
	}
	else
		check_gameover(data, map, move);
}
