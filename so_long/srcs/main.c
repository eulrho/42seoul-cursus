/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:07:53 by erho              #+#    #+#             */
/*   Updated: 2023/12/17 13:51:48 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*read_map(char *map_file)
{
	t_fopen	fopen;
	int		fd;
	char	*result;

	result = (char *)malloc(sizeof(char) * 1);
	if (result == NULL)
		print_error(MEMORY);
	result[0] = '\0';
	fd = open(map_file, O_RDONLY);
	is_valid_file(map_file, fd);
	while (1)
	{
		fopen.buff = get_next_line(fd);
		if (fopen.buff == NULL)
			break ;
		else
		{
			fopen.read_size = ft_strlen(fopen.buff);
			result = ft_strjoin(&result, fopen);
			free(fopen.buff);
		}
	}
    close(fd);
	return (result);
}

void	game(t_play *play)
{
	play->mlx = mlx_init();
	play->win = mlx_new_window(play->mlx, play->map.x_size * IMAGE_SIZE,
			play->map.y_size * IMAGE_SIZE, "so long");
	play->x = play->map.start_x;
	play->y = play->map.start_y;
	draw_map(play);
	mlx_hook(play->win, KEY_PRESS, KEY_PRESS_MASK, &key_hook, play);
	mlx_hook(play->win, EXIT_BUTTON, 0, &x_close, play);
	mlx_loop_hook(play->mlx, render_next_frame, play);
	mlx_loop(play->mlx);
}

int	main(int argc, char **argv)
{
	t_play	play;
	char	*origin_map;
	size_t	len;

	if (argc != 2)
		print_error(STANDARD_INPUT);
	origin_map = read_map(argv[1]);
	if (origin_map[0] == '\0')
		print_error(INVALID_FILE);
	len = ft_strlen(origin_map);
	if (origin_map[0] == '\n' || origin_map[len - 1] == '\n')
		print_error(INVALID_MAP);
	play.map.split_map = ft_split(origin_map, '\n');
	settings(&play);
	is_valid_map(&play.map);
	game(&play);
	return (0);
}
