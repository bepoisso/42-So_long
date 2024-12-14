/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoreboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:20:47 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/14 13:15:03 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Main function for adding score in files
void	save_in_scoreboard(t_mlx_data *data)
{
	char	**score;
	char	**user;
	int		fd;

	fd = open("./srcs/pacman.sb", O_RDWR | O_APPEND, 0777);
	if (fd == -1)
		return (ft_perror("***ERROR OPEN SCOREBOARD FILE***", data));
	split_score(fd, &score, &user);
	save_in_scoreboard_pt2(data, &score, &user);
	sort_score(&user, &score);
	print_scoreboard(user, score);
	creat_new_score(&user, &score, data);
	free_2d_mlx(user);
	free_2d_mlx(score);
	close(fd);
}

void	save_in_scoreboard_pt2(t_mlx_data *data, char ***score, char ***user)
{
	int		index;
	char	*temp;

	index = 0;
	if (get_index_of_user(*user, data->pseudo, &index) != -1
		&& comp_score(*score, data->map.move_count, index))
	{
		free((*score)[index]);
		temp = ft_itoa(data->map.move_count);
		(*score)[index] = ft_strdup(temp);
		free(temp);
	}
	else if (get_index_of_user(*user, data->pseudo, &index) == -1)
	{
		*user = add_data_in_tab(data->pseudo, *user);
		temp = ft_itoa(data->map.move_count);
		*score = add_data_in_tab(temp, *score);
		free(temp);
		
	}
}

void	collect_users(int fd, char **final_user)
{
	char	*temp;
	char	*temp_data;

	*final_user = ft_strdup("");
	temp = get_next_line(fd);
	while (temp)
	{
		temp_data = ft_strjoin(*final_user, temp);
		free(*final_user);
		*final_user = temp_data;
		free(temp);
		temp = get_next_line(fd);
		if (temp)
		{
			free(temp);
			temp = get_next_line(fd);
		}
	}
}

void	collect_scores(int fd, char **final_score)
{
	char	*temp;
	char	*temp_data;

	*final_score = ft_strdup("");
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (temp)
		{
			temp_data = ft_strjoin(*final_score, temp);
			free(*final_score);
			*final_score = temp_data;
			free(temp);
			temp = get_next_line(fd);
		}
	}
}

// Create a char tab2d (containt username and score at the same index)
// in 2 char tab
void	split_score(int fd, char ***score, char ***user)
{
	char	*final_user;
	char	*final_score;

	collect_users(fd, &final_user);
	lseek(fd, 0, SEEK_SET);
	collect_scores(fd, &final_score);
	*user = ft_split(final_user, '\n');
	*score = ft_split(final_score, '\n');
	free(final_user);
	free(final_score);
}
