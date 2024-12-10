/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_pt2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:39:43 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/10 14:24:51 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Count the number of one entity is in the map
int	entity_counter(char **map, char entity)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == entity)
				count++;
			x++;
		}
		y++;
	}
	return (count++);
}

// Check if other character is in the map
// (other than the defined and managed character)
int	check_other_char_in_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y + 1] != NULL)
	{
		x = 0;
		while (map[y][x + 1] != '\0')
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != 'W'
				&& map[y][x] != 'X' && map[y][x] != 'Y' && map[y][x] != 'Z'
				&& map[y][x] != 'T' && map[y][x] != 't')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

// Check if the map is a squar or a rectangle and not a obscure shape
int	check_map_rectangle(char **map)
{
	int	i;
	int	size_line;

	i = 0;
	size_line = ft_strlen((map[i]));
	while (map[i] != NULL)
	{
		if ((int)ft_strlen(map[i]) != size_line)
			return (1);
		i++;
	}
	return (0);
}

// Initialise the map and check if the map if valid
void	init_map(t_mlx_data *data)
{
	data->map.map = split_map("./map.ber");
	if (check_map_rectangle(data->map.map))
		ft_perror("Error\nThe map must be rectangular\n", data);
	if (check_other_char_in_map(data->map.map))
		ft_perror("Error\nThe map must be only contained \"01CEPWXYZTt\"\n",
			data);
	if (check_wall(&data->map))
		ft_perror("Error\nThe map must be bordered by a wall\n",
			data);
	if (check_entitys_in_map(data->map.map))
		ft_perror("Error\nThe map must have right entity in map\n",
			data);
	if (check_enemy_in_map(data->map.map))
		ft_perror("Error\nMissing enemy(s) in map\n", data);
	init_map_pt2(data);
}

void	init_map_pt2(t_mlx_data *data)
{
	get_entity_pos(&data->map, 'P', 1);
	data->map.temp_map = create_temp_map(data->map.map);
	if (is_valid_path(data, data->map.x, data->map.y))
		ft_perror("Error\nNo path are found betwen the player and \
exit\n", data);
	get_entity_pos(&data->map, 'P', 1);
	free_2d_mlx(data->map.temp_map);
	data->map.temp_map = create_temp_map(data->map.map);
	item_flood_fill(data, data->map.x, data->map.y);
	if (item_counter_path(data->map.temp_map))
		ft_perror("Error\nAll items can't be colected by the player \n", data);
	data->map.move_count = 0;
	data->map.item = entity_counter(data->map.map, 'C');
}
