/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:46:40 by bepoisso          #+#    #+#             */
/*   Updated: 2024/11/18 08:26:17 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemy *lst_create_enemy(int index, int pos_x, int pos_y)
{
	t_enemy	*new;

	new = (t_enemy *)malloc(sizeof(t_enemy));
	if (new == NULL)
		return (NULL);
	new->index = index;
	new->pos_x = pos_x;
	new->pos_y = pos_y;
	new->next = NULL;
	return (new);
}

void	lst_add_enemy(t_enemy **lst, t_enemy *new)
{
	t_enemy	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_list	*ft_lstlast_enemy(t_enemy *lst)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst);
	while (i < size - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	ft_lstsize_enemy(t_enemy *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
