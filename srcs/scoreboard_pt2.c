/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoreboard_pt2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:44:16 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/08 12:45:21 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Get the index of a username in the list, so the score to
int	get_index_of_user(char **user, char	*pseudo, int *index)
{
	while (user[*index])
	{
		if (ft_strncmp(pseudo, user[*index], 8) == 0)
			return (*index);
		(*index)++;
	}
	return (-1);
}

// Compare old socre of the user and the newest.
// If the newest is less than the oldest we want to remplace it
int	comp_score(char **score, int new_score, int index)
{
	int	result;

	result = ft_atoi(score[index]);
	if (result > new_score)
		return (1);
	return (0);
}

// Create a temp file and put the list of user ans score in it
// After that remove the old list and rename the newest
void	creat_new_score(char ***user, char ***score, t_mlx_data *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("./srcs/temp.sb", O_CREAT | O_APPEND | O_WRONLY, 0777);
	if (fd < 0)
		return (ft_perror("***ERROR OPEN PRIT_NEW_SCORE***", data));
	while ((*user)[i])
	{
		add_score((*user)[i], (*score)[i], fd);
		i++;
	}
	unlink("./srcs/pacman.sb");
	link("./srcs/temp.sb", "./srcs/pacman.sb");
	unlink("./srcs/temp.sb");
	close(fd);
}

// Adding a score to the files
void	add_score(char *player_name, char *player_score, int fd)
{
	ft_putendl_fd(player_name, fd);
	ft_putendl_fd(player_score, fd);
}

// Bubble sort the list The minimal number is on the top,
// the bigest on the buttom
void	sort_score(char ***user, char ***score)
{
	char	*temp_score;
	char	*temp_user;
	int		i;
	int		j;

	j = 0;
	while ((*score)[j + 1])
	{
		i = 0;
		while ((*score)[i + 1])
		{
			if (ft_atoi((*score)[i]) > ft_atoi((*score)[i + 1]))
			{
				temp_score = (*score)[i];
				temp_user = (*user)[i];
				(*score)[i] = (*score)[i + 1];
				(*user)[i] = (*user)[i + 1];
				(*score)[i + 1] = temp_score;
				(*user)[i + 1] = temp_user;
			}
			i++;
		}
		j++;
	}
}
