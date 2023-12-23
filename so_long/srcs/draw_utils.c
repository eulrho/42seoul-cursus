/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:43:44 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 14:39:00 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_tile(t_play *play, int x, int y)
{
	if (play->tile_img.image == NULL)
		save_image(play->mlx, &play->tile_img, "textures/floor.xpm");
	mlx_put_image_to_window(play->mlx, play->win, play->tile_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	draw_wall(t_play *play, int x, int y)
{
	if (play->wall_img.image == NULL)
		save_image(play->mlx, &play->wall_img, "textures/crack.xpm");
	mlx_put_image_to_window(play->mlx, play->win, play->wall_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	draw_exit(t_play *play, int x, int y)
{
	if (play->exit_img.image == NULL)
	{
		if (play->map.collection_cnt != 0)
			save_image(play->mlx, &play->exit_img, "textures/portal_bef.xpm");
		else
			save_image(play->mlx, &play->exit_img, "textures/portal_aft.xpm");
	}
	mlx_put_image_to_window(play->mlx, play->win, play->exit_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	draw_collection(t_play *play, int x, int y)
{
	if (play->coll_img.image == NULL)
		save_image(play->mlx, &play->coll_img, "textures/rat.xpm");
	mlx_put_image_to_window(play->mlx, play->win, play->coll_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	draw_character(t_play *play, int x, int y)
{
	if (play->ch_img.image == NULL)
		save_image(play->mlx, &play->ch_img, "textures/doctor_64.xpm");
	mlx_put_image_to_window(play->mlx, play->win, play->ch_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}
