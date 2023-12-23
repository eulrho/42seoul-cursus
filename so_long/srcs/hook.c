/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:15:36 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 14:39:04 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_play *play)
{
	if (keycode == KEY_UP && check_load(play, play->y - 1, play->x) == 1)
		play->y--;
	else if (keycode == KEY_DOWN && check_load(play, play->y + 1, play->x) == 1)
		play->y++;
	else if (keycode == KEY_LEFT && check_load(play, play->y, play->x - 1) == 1)
		play->x--;
	else if (keycode == KEY_RIGHT
		&& check_load(play, play->y, play->x + 1) == 1)
		play->x++;
	else if (keycode == ESC)
		x_close(play);
	if (play->map.split_map[play->y][play->x] == 'E'
			&& play->map.collection_cnt == 0)
		x_close(play);
	return (0);
}

int	render_next_frame(t_play *play)
{
	mlx_clear_window(play->mlx, play->win);
	draw_map(play);
	return (0);
}

int	x_close(t_play *play)
{
	mlx_destroy_window(play->mlx, play->win);
	exit(0);
	return (0);
}
