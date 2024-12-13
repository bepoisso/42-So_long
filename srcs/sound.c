/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:59:04 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/13 09:48:28 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <string.h>

unsigned long	hashstr(const char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	c = *str++;
	while ((c))
	{
		hash = ((hash << 5) + hash) + c;
		c = *str++;
	}
	return (hash);
}

char	*is_attenued(char *base, int attenued)
{
	if (attenued)
		base = "paplay --volume=30000 sounds/";
	else
		base = "paplay --volume=40000 sounds/";
	return (base);
}

void	playsound(char *file, int wait, int stop, int attenued)
{
	char	*base;
	char	tmp[256];
	int		result;

	base = NULL;
	base = is_attenued(base, attenued);
	ft_memset(tmp, 0, 256);
	ft_memcpy(tmp, base, strlen(base));
	if (stop)
	{
		result = system("pkill -f paplay");
		if (result != 0)
			ft_printf("Sound error stop sound %s\n", file);
	}
	if (hashstr(file) == 2784)
		return ;
	memcpy(&tmp[strlen(base)], file, strlen(file));
	if (!wait)
		base = ".ogg &";
	else
		base = ".ogg";
	memcpy(&tmp[strlen(tmp)], base, strlen(base));
	result = system(tmp);
	if (result != 0)
		ft_printf("Sound error play sound %s\n", file);
}
/*
playsound(son(.ogg), attendre la fin de la musique ou non,
stopper un son, attenuer le son);
playsound("wall_bump", 0, 0, 1);
0->65000 attenuation
playsound("music_game", 0, 0, 0);//musique du jeu
playsound("gun_fire", 1, 0, 1);

next_sound = 0;
if (clock_t() >= next_sound)
{
	next_sound = clock_t() + 150005;
	playsound("music_game", 0, 0, 0);
	sleep(1000);
	playsound("music_game2", 0, 1, 0);
}*/
