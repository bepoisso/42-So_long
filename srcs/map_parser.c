/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:02:17 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/25 12:30:47 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Count the number of line in a files
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

// Create a char 2D of the map
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

// Get the size of the map and put it in the main struct
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

// Check if all the map is bordered by a wall
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

// Check if all obligatory entity is in the map
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

// Check if other character is in the map (other than the defined and managed character)
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
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != 'W'&& map[y][x] != 'X' && map[y][x] != 'Y' && map[y][x] != 'Z' && map[y][x] != 'T' && map[y][x] != 't' && map[y][x] != 'V')
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

// I need to change that by the ft_strlen of my libft
int	ft_my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// Initialise the map and check if the map if valid
void	init_map(t_mlx_data *data)
{
	data->map.map = split_map("./map.test");
	if (check_map_rectangle(data->map.map))
	{
		ft_perror("Error\nThe map must be rectangular\n");
		mlx_destroy(data);
	}
	if (check_other_char_in_map(data->map.map))
	{
		ft_perror("Error\nThe map must be only contained \"01CEPWXYZTtV\"\n");
		mlx_destroy(data);
	}
	if (check_wall(&data->map))
	{
		ft_perror("Error\nThe map must be bordered by a wall\n");
		mlx_destroy(data);
	}
	if (check_entitys_in_map(data->map.map))
	{
		ft_perror("Error\nThe map must have right entity in map\n");
		mlx_destroy(data);
	}
	get_entity_pos(&data->map, 'P', 1);
	data->map.temp_map = create_temp_map(data->map.map);
	if (is_valid_path(data->map.temp_map, data->map.x, data->map.y))
	{
		ft_perror("Error\nNo path are found betwen the player and exit\n");
		mlx_destroy(data);
	}
	free_2d_mlx(data->map.temp_map);
	

	data->map.move_count = 0;
	data->map.item = entity_counter(data->map.map, 'C');
}

// Get the number of list in a 2D char tab (char tab[THIS][])
int	ft_strslen(char **map)
{
	int	i;

	i = 0;
	while(map[i] != NULL)
		i++;
	return (i);
}

// Create a temp map usefull for editying the map without losing informations
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

// Recurcive function that check if a path exist between the player and the exit
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
