/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:30:54 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/14 18:15:30 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_enemy(t_mlx_map *map)
{
	t_enemy *enemy;
	t_enemy *new;
	int	enemy_nbr;
	int	i;

	i = 1;
	enemy_nbr = entity_counter(map->map, 'G');
	while (i <= enemy_nbr)
	{
		new = lst_create_enemy(i, map->x, map->y);
		lst_add_enemy(enemy, new);
		i++;
	}
}
