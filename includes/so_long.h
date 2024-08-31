/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:10:42 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/31 18:07:57 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//_________________INCLUDES_________________
# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <unistd.h>

//_________________STRUCT_________________
typedef struct s_mlx_data
{
	void	*link;
	void	*screen;
}	t_mlx_data;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif
