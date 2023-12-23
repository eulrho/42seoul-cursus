/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:36:17 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 21:29:10 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_reached(t_map *m, int **visited)
{
	int	y;
	int	x;

	y = 0;
	while (y < (int)m->y_size)
	{
		x = 0;
		while (x < (int)m->x_size)
		{
			if (m->split_map[y][x] == 'C' && visited[y][x] == 0)
				return (0);
			if (m->split_map[y][x] == 'E' && visited[y][x] == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	find(int **visited, t_map *m, int y, int x)
{
	if (y < 0 || y >= (int)m->y_size || x < 0 || x >= (int)m->x_size)
		return ;
	if (m->split_map[y][x] == '1')
		return ;
	visited[y][x] = 1;
	if (visited[y][x - 1] == 0)
		find(visited, m, y, x - 1);
	if (visited[y - 1][x] == 0)
		find(visited, m, y - 1, x);
	if (visited[y][x + 1] == 0)
		find(visited, m, y, x + 1);
	if (visited[y + 1][x] == 0)
		find(visited, m, y + 1, x);
}

void	is_valid_path(t_map *m)
{
	int	**visited;
	int	i;

	i = 0;
	visited = (int **)malloc(sizeof(int *) * m->y_size);
	if (visited == NULL)
		print_error(MEMORY);
	while (i < (int)m->y_size)
	{
		visited[i] = (int *)ft_calloc(m->x_size, sizeof(int));
		if (visited[i] == NULL)
			print_error(MEMORY);
		i++;
	}
	find(visited, m, m->start_y, m->start_x);
	if (check_reached(m, visited) == 0)
		print_error(INVALID_PATH);
	i = 0;
	while (i < (int)m->y_size)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
