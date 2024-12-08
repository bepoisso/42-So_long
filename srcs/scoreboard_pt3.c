/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoreboard_pt3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:44:18 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/08 12:45:16 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
