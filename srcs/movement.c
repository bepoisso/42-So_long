/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:52 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/19 12:05:06 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		map->map[map->y][map->x - 1] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == RIGHT && map->map[map->y][map->x + 1] != '1')
	{
		check_item_counter(map, move);
		check_end(data, map, move);
		check_enemy_gameover(data, map, move);
		map->map[map->y][map->x + 1] = 'P';
		map->map[map->y][map->x] = '0';
	}
	return (map->map);
}

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

char	**enemy_move(t_mlx_data *data, t_mlx_map *map, int index, char type)
{
	int		rdm;
	char	temp;

	get_entity_pos(map, type, index);
	while (1)
	{
		rdm = (rand() % 4) + 1;
		if (rdm == UP && !is_in_set(map->map[map->y - 1][map->x], "WXYZ1"))
		{
			check_player_gameover(data, map, UP);
			temp = map->stach;
			map->stach = map->map[map->y - 1][map->x];
			map->map[map->y - 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == DOWN && !is_in_set(map->map[map->y + 1][map->x], "WXYZ1"))
		{
			check_player_gameover(data, map, DOWN);
			temp = map->stach;
			map->stach = map->map[map->y + 1][map->x];
			map->map[map->y + 1][map->x] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == LEFT && !is_in_set(map->map[map->y][map->x - 1], "WXYZ1"))
		{
			check_player_gameover(data, map, LEFT);
			temp = map->stach;
			map->stach = map->map[map->y][map->x - 1];
			map->map[map->y][map->x - 1] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
		if (rdm == RIGHT && !is_in_set(map->map[map->y][map->x + 1], "WXYZ1"))
		{
			check_player_gameover(data, map, RIGHT);
			temp = map->stach;
			map->stach = map->map[map->y][map->x + 1];
			map->map[map->y][map->x + 1] = type;
			map->map[map->y][map->x] = temp;
			break;
		}
	}
	return (map->map);
}
