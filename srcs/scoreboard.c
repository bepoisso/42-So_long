/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoreboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:20:47 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/21 11:56:55 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_in_scoreboard(t_mlx_data *data)
{
	char	**score;
	char	**user;
	int		index;
	int		fd;

	index = 0;
	fd = open("./srcs/pacman.sb", O_RDWR | O_APPEND);
	if (!fd)
		return ((void)ft_printf("***ERROR OPEN MAIN FILE***"));
	split_score(fd, &score, &user);
	if (get_index_of_user(&user, data->pseudo, &index) != -1)
	{
		index = get_index_of_user(&user, data->pseudo, 0);
		if (comp_score(&score, data->map.move_count, index))
		{
			free(score[index]);
			score[index] = ft_strdup(ft_itoa(data->map.move_count));
		}
	}
	else
		add_score(data->pseudo, ft_itoa(data->map.move_count), fd);
	sort_score(&user, &score);
	print_new_score(&user, &score);
	aff_scoreboard(fd);
	close(fd);

}

void	split_score(int	fd, char ***score, char ***user)
{
	char	*final_score;
	char	*final_user;
	char	*temp;

	temp = get_next_line(fd);
	while(temp)
	{
		ft_strjoin(final_user, temp);
		temp = get_next_line(fd);
		ft_strjoin(final_score, temp);
		temp = get_next_line(fd);
	}
	*user = ft_split(final_user, '\n');
	*score = ft_split(final_score, '\n');
}

int	get_index_of_user(char ***user, char	*pseudo, int *index)
{
	while(*user[*index])
	{
		if (ft_strncmp(pseudo, *user[*index], 8) == 0)
			return (*index);
		(*index)++;
	}
	return (-1);
}

int	comp_score(char ***score, int new_score, int index)
{
	int	result;

	result = ft_atoi(*score[index]);
	if (result < new_score)
		return (1);
	return (0);
}

void	print_new_score(char ***user, char ***score)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("./srcs/temp.sb", O_CREAT | O_APPEND | O_WRONLY);
	if (fd < 0)
		return ((void)ft_printf("***ERROR OPEN PRIT_NEW_SCORE***"));

	while(*user[i])
	{
		add_score(*user[i], *score[i], fd);
		i++;
	}
	unlink("./srcs/pacman.sb");
	link("./srcs/temp.sb", "./srcs/pacman.sb");
	unlink("./srcs/temp.sb");
	close(fd);
}

void	add_score(char *player_name, char *player_score, int fd)
{
	ft_putendl_fd(player_name, fd);
	ft_putendl_fd(player_score, fd);
}

void	sort_score(char ***user, char ***score)
{
	char	*temp_score;
	char	*temp_user;
	int		i;
	int		j;

	j = 0;
	while(*score[j + 1])
	{
		i = 0;
		while (*score[i + 1])
		{
			if (ft_atoi(*score[i]) > ft_atoi(*score[i + 1]))
			{
				temp_score = *score[i];
				temp_user = *user[i];
				*score[i] = *score[i + 1];
				*user[i] = *user[i + 1];
				*score[i + 1] = temp_score;
				*user[i + 1] = temp_user;
			}
			i++;
		}
		j++;
	}
}


void	aff_scoreboard(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		ft_printf("%s", str);
		str = get_next_line(fd);
	}
}
