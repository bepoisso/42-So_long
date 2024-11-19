/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoreboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:20:47 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/19 17:18:36 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//PLAYER\nSCORE\n

void	save_in_scoreboard(t_mlx_data *data)
{
	char	**score;
	char	**user;
	int		index;

	split_score("./srcs/pacman.sb", score, user);
	if (get_index_of_user(user, data->pseudo, 0) != -1)
		index = get_index_of_user(user, data->pseudo, 0);
		if (comp_score(score, data->map.move_count, index))
			score[index] = data->map.move_count;
		else
		{
			print_new_scoreboard(score, user, "./srcs/pacman.sb")
			add_score();
		}
	sort_score();
	aff_scoreboard();

}

void	split_score(char *file, char **score, char **user)
{
	int		fd;
	char	*final_score;
	char	*final_user;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (ft_printf("***ERROR OPEN SPLIT_SCORE***"), NULL);
	temp = get_next_line(fd);
	while(temp)
	{
		ft_strjoin(final_user, temp);
		temp = get_next_line(fd);
		ft_strjoin(final_score, temp);
		temp = get_next_line(fd);
	}
	user = ft_split(final_user, '\n');
	score = ft_split(final_score, '\n');
}

int	get_index_of_user(char **user, char	*pseudo, int *index)
{
	while(user[*index])
	{
		if (ft_strncmp(pseudo, user[*index], 8) == 0)
			return (*index);
		*index++;
	}
	return (-1);
}

int	comp_score(char **score, int new_score, int index)
{
	int	result;

	result = ft_atoi(score[index]);
	if (result < new_score)
		return (1);
	return (0);
}

void	print_new_scoreboard(char **score, char **user, char *file)
{
	int	i;
	int	fd;

	fd = open(file, O_APPEND | O_WRONLY);
	if (!fd)
		return (ft_printf("***ERROR OPEN PRINT_NEW_SCOREBOARD***"), NULL);
	i = 0;
	while(user[i])
	{
		ft_putendl_fd(user[i], fd);
		ft_putnbr_fd(score[i], fd);
		ft_putchar_fd('\n', fd);
	}
}

void	add_score(char *player_name, int player_score, char *file)
{
	int	fd;

	fd = open(file, O_APPEND | O_WRONLY);
	if (!fd)
		return (ft_printf("***ERROR OPEN ADD_SCORE***"), NULL);
	ft_putendl_fd(player_name, fd);
	ft_putnbr_fd(player_score, fd);
	ft_putchar_fd('\n', fd);
}

void	sort_score()
{

}


void	aff_scoreboard()
{

}