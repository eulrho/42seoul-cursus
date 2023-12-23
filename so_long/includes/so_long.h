/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:27:20 by erho              #+#    #+#             */
/*   Updated: 2023/12/17 13:31:15 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMAGE_SIZE 64

// mask code
# define KEY_PRESS_MASK 1

// mac key codes
# define LEFT_CLICK 1
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define ESC 53
# define KEY_PRESS 2
# define EXIT_BUTTON 17

// error codes
# define VALID 1
# define OTHER_CHARACTERS 2
# define MEMORY 3
# define FILE_NAME 4
# define STANDARD_INPUT 5
# define INVALID_FILE 6
# define INVALID_MAP 7
# define INVALID_PATH 8
# define MAP_SIZE 9
# define OVER_FLOW 10

# include <fcntl.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_image {
	void	*image;
	int		width;
	int		height;
}	t_image;

typedef struct s_map
{
	char	**split_map;
	size_t	y_size;
	size_t	x_size;
	int		start_y;
	int		start_x;
	int		start_cnt;
	int		end_cnt;
	int		collection_cnt;
}	t_map;

typedef struct s_play {
	void	*mlx;
	void	*win;
	t_image	ch_img;
	t_image	tile_img;
	t_image	wall_img;
	t_image	coll_img;
	t_image	exit_img;
	int		y;
	int		x;
	t_map	map;
	int		move;
}	t_play;

// length
size_t	ft_two_dim_len(char **str);
size_t	ft_nbrlen_base(unsigned long long n, int base_nb);
size_t	ft_strlen(const char *str);

// check_valid
void	is_valid_file(char *file, int fd);
void	is_valid_map(t_map *m);
void	is_valid_path(t_map *m);
void	print_error(int error_no);

// utils
char	**ft_split(char const *s, char c);
void	settings(t_play *play);
void	save_image(void *mlx, t_image *img, char *file);
int		check_load(t_play *play, int y, int x);
void	foot_print(int move);
void	*ft_calloc(size_t n, size_t size);

// draw
void	draw_character(t_play *play, int x, int y);
void	draw_tile(t_play *play, int x, int y);
void	draw_collection(t_play *play, int x, int y);
void	draw_exit(t_play *play, int x, int y);
void	draw_wall(t_play *play, int x, int y);
void	draw_map(t_play *play);

// hook
int		key_hook(int keycode, t_play *play);
int		render_next_frame(t_play *play);
int		x_close(t_play *play);

#endif
