/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:33:13 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 14:39:01 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_map(t_play *play)
{
	int	y;
	int	x;

	y = 0;
	while (y < (int)play->map.y_size)
	{
		x = 0;
		while (x < (int)play->map.x_size)
		{
			draw_tile(play, x, y);
			if (play->map.split_map[y][x] == '1')
				draw_wall(play, x, y);
			else if (play->map.split_map[y][x] == 'C'
					&& play->map.collection_cnt != 0)
				draw_collection(play, x, y);
			else if (play->map.split_map[y][x] == 'E')
				draw_exit(play, x, y);
			if (play->x == x && play->y == y)
				draw_character(play, x, y);
			x++;
		}
		y++;
	}
}
