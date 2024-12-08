/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_pt3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:41:04 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/08 12:41:44 by bepoisso         ###   ########.fr       */
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
int	is_valid_path(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	map[y][x] = 'V';
	if (is_valid_path(map, x + 1, y) == 0
		|| is_valid_path(map, x - 1, y) == 0
		|| is_valid_path(map, x, y + 1) == 0
		|| is_valid_path(map, x, y - 1) == 0)
		return (0);
	return (1);
}

int	item_counter_path(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
