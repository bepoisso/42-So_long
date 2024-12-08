/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:03:30 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/08 13:03:51 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// taking all po of all entity
void	taking_pos(t_mlx_data *data)
{
	get_entity_pos(&data->map, PLAYER, 1);
	data->player.x = data->map.x;
	data->player.y = data->map.y;
	get_entity_pos(&data->map, BLINKY, 1);
	data->enemy.blinky.x = data->map.x;
	data->enemy.blinky.y = data->map.y;
	data->enemy.blinky.stash = '0';
	get_entity_pos(&data->map, PINKY, 1);
	data->enemy.pinky.x = data->map.x;
	data->enemy.pinky.y = data->map.y;
	data->enemy.pinky.stash = '0';
	get_entity_pos(&data->map, INKY, 1);
	data->enemy.inky.x = data->map.x;
	data->enemy.inky.y = data->map.y;
	data->enemy.inky.stash = '0';
	get_entity_pos(&data->map, CLYDE, 1);
	data->enemy.clyde.x = data->map.x;
	data->enemy.clyde.y = data->map.y;
	data->enemy.clyde.stash = '0';
}

void	init_value(t_mlx_data *data, char **av)
{
	srand(time(NULL));
	data->current_frame = 0;
	data->map.stach = '0';
	data->pseudo = av[1];
	data->player.last_move = 3;
	data->help.frame = 1;
	init_map(data);
	taking_pos(data);
}
