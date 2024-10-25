/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:46:52 by bepoisso          #+#    #+#             */
/*   Updated: 2024/10/25 11:37:56 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**player_move(t_mlx_data *data, t_mlx_map *map, int move)
{
	get_player_pos(map);
	if (move == UP && map->map[map->y - 1][map->x] != '1')
	{
		check_item_counter(map, move);
		check_end(data, map, move);
		map->map[map->y - 1][map->x] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == DOWN && map->map[map->y + 1][map->x] != '1')
	{
		check_item_counter(map, move);
		check_end(data, map, move);
		map->map[map->y + 1][map->x] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == LEFT && map->map[map->y][map->x - 1] != '1')
	{
		check_item_counter(map, move);
		check_end(data, map, move);
		map->map[map->y][map->x - 1] = 'P';
		map->map[map->y][map->x] = '0';
	}
	else if (move == RIGHT && map->map[map->y][map->x + 1] != '1')
	{
		check_item_counter(map, move);
		check_end(data, map, move);
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
			mlx_destroy(data);
		}
		else if (move == DOWN && map->map[map->y + 1][map->x] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			mlx_destroy(data);
		}
		else if (move == LEFT && map->map[map->y][map->x - 1] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			mlx_destroy(data);
		}
		else if (move == RIGHT && map->map[map->y][map->x + 1] == 'E')
		{
			ft_printf("\n ***FINISH IN %d MOVE ***\n", map->move_count);
			mlx_destroy(data);
		}
	}
	else
		check_gameover(data, map, move);
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

void	get_player_pos(t_mlx_map *map)
{
	int	x;
	int	y;
	
	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			if (map->map[y][x] == 'P')
			{
				map->x = x;
				map->y = y;
			}
			x++;
		}
		y++;
	}
}
