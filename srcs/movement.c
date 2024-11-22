/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:52 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/22 11:19:43 by bepoisso         ###   ########.fr       */
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
	get_entity_pos(map, 'P', 1);
	if (move == UP && map->map[map->y - 1][map->x] != '1')
	{
		check_item_counter(map, move);
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		map->map[map->y - 1][map->x] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == DOWN && map->map[map->y + 1][map->x] != '1')
	{
		check_item_counter(map, move);
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		map->map[map->y + 1][map->x] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == LEFT && map->map[map->y][map->x - 1] != '1')
	{
		check_item_counter(map, move);
		check_tp('P', map, LEFT);
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		map->map[map->y][map->x - 1] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == RIGHT && map->map[map->y][map->x + 1] != '1')
	{
		check_item_counter(map, move);
		check_tp('P', map, RIGHT);
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		map->map[map->y][map->x + 1] = 'P';
		map->map[map->y][map->x] = '0';
	}
	return (map->map);
}

// Check if the player taking a items and decramante the counter
void	check_item_counter(t_mlx_map *map, int move)
{
	
	if (move == UP && map->map[map->y - 1][map->x] == 'C')
		map->item--;
	else if (move == DOWN && map->map[map->y + 1][map->x] == 'C')
		map->item--;
	else if (move == LEFT && map->map[map->y][map->x - 1] == 'C')
		map->item--;
	else if (move == RIGHT && map->map[map->y][map->x + 1] == 'C')
		map->item--;
}

// Check if the player want to exit and if hi as all the items
// if it is adding the score on scorebord or game over
void	check_end(t_mlx_data *data, t_mlx_map *map, int move)
{
	if (map->item == 0)
	{
		if (move == UP && map->map[map->y - 1][map->x] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			save_in_scoreboard(data);
			mlx_destroy(data);
		}
		else if (move == DOWN && map->map[map->y + 1][map->x] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			save_in_scoreboard(data);
			mlx_destroy(data);
		}
		else if (move == LEFT && map->map[map->y][map->x - 1] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			save_in_scoreboard(data);
			mlx_destroy(data);
		}
		else if (move == RIGHT && map->map[map->y][map->x + 1] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			save_in_scoreboard(data);
			mlx_destroy(data);
		}
	}
	else
		check_gameover(data, map, move);
}

// Check if the player hit a ennemt and if it is game over it
void	check_enemy_gameover(t_mlx_data *data, t_mlx_map *map, int move)
{
	if (move == UP &&  is_in_set(map->map[map->y - 1][map->x], "WXYZ"))
	{
		ft_printf("\n ***GAME OVER A ENEMY KILL YOU***\n");
		mlx_destroy(data);
	}
	else if (move == DOWN &&  is_in_set(map->map[map->y + 1][map->x], "WXYZ"))
	{
		ft_printf("\n ***GAME OVER GHOSTY KILL YOU***\n");
		mlx_destroy(data);
	}
	else if (move == LEFT &&  is_in_set(map->map[map->y][map->x - 1], "WXYZ"))
	{
		ft_printf("\n ***GAME OVER GHOSTY KILL YOU***\n");
		mlx_destroy(data);
	}
	else if (move == RIGHT &&  is_in_set(map->map[map->y][map->x + 1], "WXYZ"))
	{
		ft_printf("\n ***GAME OVER GHOSTY KILL YOU***\n");
		mlx_destroy(data);
	}
}

// Check if the ennemy hit the player and if it is game over it
void	check_player_gameover(t_mlx_data *data, t_mlx_map *map, int move)
{
	if (move == UP && map->map[map->y - 1][map->x] == 'P')
	{
		ft_printf("\n ***GAME OVER GHOSTY KILL YOU***\n");
		mlx_destroy(data);
	}
	else if (move == DOWN && map->map[map->y + 1][map->x] == 'P')
	{
		ft_printf("\n ***GAME OVER GHOSTY KILL YOU***\n");
		mlx_destroy(data);
	}
	else if (move == LEFT && map->map[map->y][map->x - 1] == 'P')
	{
		ft_printf("\n ***GAME OVER GHOSTY KILL YOU***\n");
		mlx_destroy(data);
	}
	else if (move == RIGHT && map->map[map->y][map->x + 1] == 'P')
	{
		ft_printf("\n ***GAME OVER GHOSTY KILL YOU***\n");
		mlx_destroy(data);
	}
}

// Check if the player want to exit and if he not have
// All the items
void	check_gameover(t_mlx_data *data, t_mlx_map *map, int move)
{
	if (move == UP && map->map[map->y - 1][map->x] == 'E')
	{
		ft_printf("\n ***GAME OVER %d ITEM MISSING***\n",map->item);
		mlx_destroy(data);
	}
	else if (move == DOWN && map->map[map->y + 1][map->x] == 'E')
	{
		ft_printf("\n ***GAME OVER %d ITEM MISSING***\n",map->item);
		mlx_destroy(data);
	}
	else if (move == LEFT && map->map[map->y][map->x - 1] == 'E')
	{
		ft_printf("\n ***GAME OVER %d ITEM MISSING***\n",map->item);
		mlx_destroy(data);
	}
	else if (move == RIGHT && map->map[map->y][map->x + 1] == 'E')
	{
		ft_printf("\n ***GAME OVER %d ITEM MISSINg***\n",map->item);
		mlx_destroy(data);
	}
}

// Get the pos of a entity and return this pos in the main struct
void	get_entity_pos(t_mlx_map *map, char entity, int index)
{
	int	x;
	int	y;
	int	i;

	i = 1;
	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			if (map->map[y][x] == entity)
			{
				if (i == index)
				{
					map->x = x;
					map->y = y;
					return;
				}
				else
					i++;
			}
			x++;
		}
		y++;
	}
}

// Check if the char (pos) is in the list (set)
int	is_in_set(char pos, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (pos == set[i])
			return (1);
		i++;
	}
	return (0);
}

// Manage the mouvement of Pinky
char	**pinky_move(t_mlx_data *data, t_mlx_map *map)
{
	int		rdm;
	int		i;
	char	temp;
	char	type;
	
	type = PINKY;
	i = 0;
	rdm = next_move(PINKY, data);
	get_entity_pos(&data->map, PINKY, 1);
	while (i < 10)
	{
		i++;
		rdm = next_move(type, data);
		if (rdm == UP && !is_in_set(map->map[map->y - 1][map->x], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, UP);
			temp = map->stach;
			map->stach = map->map[map->y - 1][map->x];
			map->map[map->y - 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == DOWN && !is_in_set(map->map[map->y + 1][map->x], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, DOWN);
			temp = map->stach;
			map->stach = map->map[map->y + 1][map->x];
			map->map[map->y + 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == LEFT && !is_in_set(map->map[map->y][map->x - 1], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, LEFT);
			temp = map->stach;
			map->stach = map->map[map->y][map->x - 1];
			map->map[map->y][map->x - 1] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == RIGHT && !is_in_set(map->map[map->y][map->x + 1], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, RIGHT);
			temp = map->stach;
			map->stach = map->map[map->y][map->x + 1];
			map->map[map->y][map->x + 1] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
	}
	data->enemy.pinky.last_move = rdm + pow(-1, rdm + 1);
	return (map->map);
}

// Manage the mouvement of Inky
char	**inky_move(t_mlx_data *data, t_mlx_map *map)
{
	int		rdm;
	int		i;
	char	temp;
	char	type;
	
	type = INKY;
	i = 0;
	rdm = next_move(INKY, data);
	get_entity_pos(&data->map, INKY, 1);
	while (i < 10)
	{
		i++;
		rdm = next_move(type, data);
		if (rdm == UP && !is_in_set(map->map[map->y - 1][map->x], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, UP);
			temp = map->stach;
			map->stach = map->map[map->y - 1][map->x];
			map->map[map->y - 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == DOWN && !is_in_set(map->map[map->y + 1][map->x], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, DOWN);
			temp = map->stach;
			map->stach = map->map[map->y + 1][map->x];
			map->map[map->y + 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == LEFT && !is_in_set(map->map[map->y][map->x - 1], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, LEFT);
			temp = map->stach;
			map->stach = map->map[map->y][map->x - 1];
			map->map[map->y][map->x - 1] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == RIGHT && !is_in_set(map->map[map->y][map->x + 1], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, RIGHT);
			temp = map->stach;
			map->stach = map->map[map->y][map->x + 1];
			map->map[map->y][map->x + 1] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
	}
	data->enemy.inky.last_move = rdm + pow(-1, rdm + 1);
	return (map->map);
}

// Manage the mouvement of Clyde
char	**clyde_move(t_mlx_data *data, t_mlx_map *map)
{
	int		rdm;
	int		i;
	char	temp;
	char	type;
	
	type = CLYDE;
	i = 0;
	rdm = next_move(CLYDE, data);
	get_entity_pos(&data->map, CLYDE, 1);
	
	while (i < 10)
	{
		i++;
		rdm = next_move(type, data);
		if (rdm == UP && !is_in_set(map->map[map->y - 1][map->x], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, UP);
			temp = map->stach;
			map->stach = map->map[map->y - 1][map->x];
			map->map[map->y - 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == DOWN && !is_in_set(map->map[map->y + 1][map->x], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, DOWN);
			temp = map->stach;
			map->stach = map->map[map->y + 1][map->x];
			map->map[map->y + 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == LEFT && !is_in_set(map->map[map->y][map->x - 1], "WXYZ1Tt"))
		{
			check_player_gameover(data, map, LEFT);
			temp = map->stach;
			map->stach = map->map[map->y][map->x - 1];
			map->map[map->y][map->x - 1] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == RIGHT && !is_in_set(map->map[map->y][map->x + 1], "WXYZ1Tt"))
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




