/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:02:17 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/19 10:36:24 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	files_count_line(char *file_name)
{
	char	buf[1];
	int		count;
	char	fd;
	char	readed;

	count = 0;
	readed = 1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (readed != 0)
	{
		readed = read(fd, buf, 1);
		if (*buf == '\n')
			count++;
	}
	close(fd);
	return (count);
}

char	**split_map(char *file_name)
{
	int		count_line;
	char	**map;
	int		i;
	int		fd;

	i = 0;
	if (!file_name || file_name[0] == '\0')
		return (NULL);
	count_line = files_count_line(file_name);
	map = (char **)malloc(sizeof(char *) * (count_line + 1));
	fd = open(file_name, O_RDONLY);
	if (count_line < 0 || map == NULL || fd == -1)
		return (NULL);
	while (i < count_line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	map_xy_size(t_mlx_map *map)
{
	map->x = 0;
	map->y = 0;
	map->y_max = 0;
	while (map->map[map->y_max])
	{
		map->x_max = 0;
		while (map->map[map->y_max][map->x_max])
			map->x_max++;
		map->y_max++;
	}
	map->x_max--;
	map->y_max--;
}

int	check_wall(t_mlx_map *map)
{
	int	x;
	int	y;

	map_xy_size(map);
	y = 0;
	x = 0;
	while (x < map->x_max)
	{
		if (map->map[y][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (y < map->y_max)
	{
		if (map->map[y][x] != '1' || map->map[y][map->x_max - 1] != '1')
			return (1);
		y++;
	}
	while (x < map->x_max)
	{
		if (map->map[map->y_max][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_entitys_in_map(char **map)
{
	t_entity_check	entity;
	int				x;
	int				y;

	entity.player_check = 0;
	entity.exit_check = 0;
	entity.item_check = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				entity.player_check++;
			if (map[y][x] == 'E')
				entity.exit_check++;
			if (map[y][x] == 'C')
				entity.item_check++;
		}
	}
	if (entity.player_check != 1 || entity.exit_check != 1
		|| entity.item_check == 0)
		return (1);
	return (0);
}

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
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != 'W'&& map[y][x] != 'X' && map[y][x] != 'Y' && map[y][x] != 'Z')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_rectangle(char **map)
{
	int	i;
	int size_line;

	i = 0;
	size_line = ft_my_strlen((map[i]));
	while (map[i] != NULL)
	{
		if (ft_my_strlen(map[i]) != size_line)
			return (1);
		i++;
	}
	return (0);
}

int	ft_my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	init_map(t_mlx_data *data)
{
	data->map.map = split_map("./map.test");
	if (check_map_rectangle(data->map.map))
	{
		ft_printf("Error\nThe map must be rectangular\n");
		mlx_destroy(data);
	}
	if (check_other_char_in_map(data->map.map))
	{
		ft_printf("Error\nThe map must be only contained \"01CEPG\"\n");
		mlx_destroy(data);
	}
	if (check_wall(&data->map))
	{
		ft_printf("Error\nThe map must be bordered by a wall\n");
		mlx_destroy(data);
	}
	if (check_entitys_in_map(data->map.map))
	{
		ft_printf("Error\nThe map must have right entity in map\n");
		mlx_destroy(data);
	}
	get_entity_pos(&data->map, 'P', 1);
	data->map.temp_map = create_temp_map(data->map.map);
	if (is_valid_path(data->map.temp_map, data->map.x, data->map.y))
	{
		ft_printf("Error\nNo path are found betwen the player and exit\n");
		mlx_destroy(data);
	}
	free_2d(data->map.temp_map);
	

	data->map.move_count = 0;
	data->map.item = entity_counter(data->map.map, 'C');
}

int	ft_strslen(char **map)
{
	int	i;

	i = 0;
	while(map[i] != NULL)
		i++;
	return (i);
}

char **create_temp_map(char **map)
{
	char **temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(char *) * (ft_strslen(map) + 1));
	while (i < ft_strslen(map))
	{
		temp[i] = ft_strdup(map[i]);
		i++;
	}
	temp[i] = NULL;
	return(temp);
}

int	is_valid_path(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	map[y][x] = 'V';
	if (is_valid_path(map, x + 1, y) == 0 ||
		is_valid_path(map, x - 1, y) == 0 ||
		is_valid_path(map, x, y + 1) == 0 ||
		is_valid_path(map, x, y - 1) == 0)
		return (0);
	return (1);
}
