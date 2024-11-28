/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoreboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:20:47 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/28 17:38:10 by bepoisso         ###   ########.fr       */
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
		return (ft_perror("***ERROR OPEN MAIN FILE***", data));
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
	int	index;

	index = 0;
	if (get_index_of_user(*user, data->pseudo, &index) != -1
		&& comp_score(*score, data->map.move_count, index))
	{
		free((*score)[index]);
		(*score)[index] = ft_strdup(ft_itoa(data->map.move_count));
	}
	else if (get_index_of_user(*user, data->pseudo, &index) == -1)
	{
		*user = add_data_in_tab(data->pseudo, *user);
		*score = add_data_in_tab(ft_itoa(data->map.move_count), *score);
	}
}

// Create a char tab2d (containt username and score at the same index)
// in 2 char tab
void	split_score(int fd, char ***score, char ***user)
{
	char	*final_score;
	char	*final_user;
	char	*temp;

	final_score = ft_strdup("");
	final_user = ft_strdup("");
	temp = get_next_line(fd);
	while (temp)
	{
		final_user = ft_strjoin(final_user, encrypt(temp));
		temp = get_next_line(fd);
		final_score = ft_strjoin(final_score, encrypt(temp));
		temp = get_next_line(fd);
	}
	*user = ft_split(final_user, '\n');
	*score = ft_split(final_score, '\n');
	free(temp);
	free(final_score);
	free(final_user);
}

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
		add_score(encrypt((*user)[i]), encrypt((*score)[i]), fd);
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

// Adding data in a tab, and add a NULL byte at the end
char	**add_data_in_tab(char *data, char **tab)
{
	int		i;
	int		size_tab;
	char	**new_tab;

	i = 0;
	size_tab = ft_strslen(tab);
	new_tab = (char **)malloc(sizeof(char *) * (size_tab + 2));
	if (!new_tab)
		return (NULL);
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = ft_strdup(data);
	new_tab[i + 1] = NULL;
	free_2d_mlx(tab);
	return (new_tab);
}

// Fonction pour ajouter des espaces à droite
void	add_spaces_right(char *str, int width)
{
	int	len;
	int	spaces;

	len = ft_strlen(str);
	spaces = width - len;
	while (spaces-- > 0)
		ft_putchar_fd(' ', 1);
}

// Fonction pour ajouter des espaces à gauche
void	add_spaces_left(char *str, int width)
{
	int	len;
	int	spaces;

	len = ft_strlen(str);
	spaces = width - len;
	while (spaces-- > 0)
		ft_putchar_fd(' ', 1);
}

// Fonction pour afficher le tableau formaté
void	print_scoreboard(char **user, char **score)
{
	int	i;

	i = 0;
	ft_printf("\n\n");
	ft_printf("+------------------+-------------+\n");
	ft_printf("|           SCOREBOARD           |\n");
	ft_printf("+------------------+-------------+\n");
	ft_printf("| Player           | Score       |\n");
	ft_printf("+------------------+-------------+\n");
	while (user[i] && score[i])
	{
		ft_printf("| ");
		ft_putstr(user[i]);
		add_spaces_right(user[i], 16);
		ft_printf(" | ");
		ft_putstr(score[i]);
		add_spaces_right(score[i], 11);
		ft_printf(" |\n");
		i++;
	}
	ft_printf("+------------------+-------------+\n");
}

// Encrypt or decrypt the string, keep in the printable ascii range
// and return the string
char	*encrypt(char *data)
{
	char	*original_data;
	char	key;

	key = 0x42;
	original_data = data;
	while (*data)
	{
		if (*data != '\n')
		{
			*data = (*data ^ key);
			if (*data < 32)
				*data = 32 + (*data % 95);
			else if (*data > 126)
				*data = 32 + ((*data - 32) % 95);
		}
		data++;
	}
	return (original_data);
}
