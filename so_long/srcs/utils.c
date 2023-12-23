/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:42:44 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 14:39:12 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_load(t_play *play, int y, int x)
{
	if (play->map.split_map[y][x] == '1')
		return (0);
	if (play->map.split_map[y][x] == 'C')
	{
		play->map.collection_cnt--;
		play->map.split_map[y][x] = '0';
		if (play->map.collection_cnt == 0)
			play->exit_img.image = NULL;
	}
	play->move++;
	foot_print(play->move);
	return (1);
}

void	settings(t_play *play)
{
	play->ch_img.image = NULL;
	play->tile_img.image = NULL;
	play->wall_img.image = NULL;
	play->coll_img.image = NULL;
	play->exit_img.image = NULL;
	play->y = 0;
	play->x = 0;
	play->move = 0;
	play->map.start_cnt = 0;
	play->map.end_cnt = 0;
	play->map.collection_cnt = 0;
}

void	foot_print(int move)
{
	ft_printf("moves : %d\n", move);
}

void	save_image(void *mlx, t_image *img, char *file)
{
	img->image = mlx_xpm_file_to_image(mlx, file, &img->width, &img->height);
}
