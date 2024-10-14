/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:02:17 by bepoisso          #+#    #+#             */
/*   Updated: 2024/10/14 14:52:49 by bepoisso         ###   ########.fr       */
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

t_manip_map	map_xy_size(char **map_char)
{
	t_manip_map	map;

	map.x = 0;
	map.y = 0;
	map.y_max = 0;
	while (map_char[map.y_max])
	{
		map.x_max = 0;
		while (map_char[map.y_max][map.x_max])
			map.x_max++;
		map.y_max++;
	}
	return (map);
}

int	map_check_wall(char **map)
{
	t_manip_map	i;

	if (!map || !*map)
		return (1);
	i = map_xy_size(map);
	i.y = 0;
	while (i.y < i.y_max - 1)
	{
		i.x = 0;
		while (i.x < i.x_max)
		{
			if (i.y < i.y_max - 1 && i.x - 1 == 0 && map[i.y][i.x] != 1)
				return (1);
			if (i.y == 0 && i.x < i.x_max - 1 && map[i.y][i.x] != 1)
				return (1);
			if (i.y < i.y_max - 1 && i.x == i.x_max - 1 && map[i.y][i.x] != 1)
				return (1);
			if (i.y == i.y_max - 1 && i.x < i.x_max - 1 && map[i.y][i.x] != 1)
				return (1);
			i.x++;
		}
		i.y++;
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
		|| entity.item_check < 1)
		return (1);
	return (0);
}
