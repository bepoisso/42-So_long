/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_pt3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:41:04 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/10 08:44:40 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Get the number of list in a 2D char tab (char tab[THIS][])
int	ft_strslen(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

// Create a temp map usefull for editying the map without losing informations
char	**create_temp_map(char **map)
{
	char	**temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char *) * (ft_strslen(map) + 1));
	while (i < ft_strslen(map))
	{
		temp[i] = ft_strdup(map[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

// Recurcive function that check if a path exist between the player and the exit
int	is_valid_path(t_mlx_data *data, int x, int y)
{
	if (data->map.temp_map[y][x] == 'C')
		data->map.temp_item++;
	if (data->map.temp_map[y][x] == 'E')
		return (0);
	if (data->map.temp_map[y][x] == '1' || data->map.temp_map[y][x] == 'V')
		return (1);
	data->map.temp_map[y][x] = 'V';
	if (is_valid_path(data, x + 1, y) == 0
		|| is_valid_path(data, x - 1, y) == 0
		|| is_valid_path(data, x, y + 1) == 0
		|| is_valid_path(data, x, y - 1) == 0)
		return (0);
	return (1);
}

int	item_counter_path(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.temp_map[y] != NULL)
	{
		x = 0;
		while (data->map.temp_map[y][x] != '\0')
		{
			if (data->map.temp_map[y][x] == 'C')
				data->map.temp_item++;
			x++;
		}
		y++;
	}
	if (data->map.temp_item != data->map.item)
		return (1);
	return (0);
}

int	check_enemy_in_map(char **map)
{
	t_entity_check	entity;
	int				x;
	int				y;

	ft_memset(&entity , 0, sizeof(entity));
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'W')
				entity.blinky++;
			if (map[y][x] == 'X')
				entity.pinky++;
			if (map[y][x] == 'Y')
				entity.inky++;
			if (map[y][x] == 'Z')
				entity.clyde++;
		}
	}
	if (entity.blinky != 1 || entity.pinky != 1
		|| entity.inky != 1 || entity.clyde != 1)
		return (1);
	return (0);
}
