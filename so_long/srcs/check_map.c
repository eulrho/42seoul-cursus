/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:16:04 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 18:25:18 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_valid_map_config(t_map *m, int y, int x)
{
	if ((y == 0 || y == (int)m->y_size - 1) && m->split_map[y][x] != '1')
		print_error(INVALID_MAP);
	if ((x == 0 || x == (int)m->x_size - 1) && m->split_map[y][x] != '1')
		print_error(INVALID_MAP);
	if (m->split_map[y][x] != '0' && m->split_map[y][x] != '1'
			&& m->split_map[y][x] != 'C' && m->split_map[y][x] != 'E'
			&& m->split_map[y][x] != 'P')
		print_error(INVALID_MAP);
	if (m->split_map[y][x] == 'P')
	{
		m->start_y = y;
		m->start_x = x;
		m->start_cnt++;
	}
	else if (m->split_map[y][x] == 'C')
		m->collection_cnt++;
	else if (m->split_map[y][x] == 'E')
		m->end_cnt++;
}

void	is_valid_config_count(t_map *m)
{
	if (m->collection_cnt == 0)
		print_error(INVALID_MAP);
	if (m->end_cnt != 1)
		print_error(INVALID_MAP);
	if (m->start_cnt != 1)
		print_error(INVALID_MAP);
}

void	is_valid_rectangle(t_map *m, int y)
{
	if (ft_strlen(m->split_map[y]) != m->x_size)
		print_error(MAP_SIZE);
}

void	is_valid_map(t_map *m)
{
	int		y;
	int		x;

	m->y_size = ft_two_dim_len(m->split_map);
	m->x_size = ft_strlen(m->split_map[0]);
	y = 0;
	while (y < (int)m->y_size)
	{
		is_valid_rectangle(m, y);
		x = 0;
		while (x < (int)m->x_size)
		{
			is_valid_map_config(m, y, x);
			x++;
		}
		y++;
	}
	is_valid_config_count(m);
	is_valid_path(m);
}
