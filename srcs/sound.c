/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:59:04 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/10 14:59:50 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

char	*is_attenued(char *base, int attenued)
{
	if (attenued)
		base = "paplay --volume=30000 sound/";
	else
		base = "paplay --volume=40000 sound/";
	return (base);
}

void	playsound(char *file, int wait, int stop, int attenued)
{
	char	*base;
	char	tmp[256];
	int		result;

	base = NULL;
	base = is_attenued(base, attenued);
	memset(tmp, 0, 256);
	memcpy(tmp, base, strlen(base));
	if (stop)
	{
		result = system("pkill -f paplay");
		if (result != 0)
			perror("");
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
		perror("");
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