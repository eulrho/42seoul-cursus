/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:09:19 by erho              #+#    #+#             */
/*   Updated: 2023/10/30 16:03:34 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 49152
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct fopen
{
	ssize_t	read_size;
	char	*buff;
	size_t	str_size;
	int		is_newline;
}	t_fopen;

char	*get_next_line(int fd);
size_t	ft_strlcat(char *dest, char *src, size_t len);
char	*ft_strndup(char *str, int len);
char	*ft_strjoin(char **s1, t_fopen fopen);
char	*move_address(char **lst, size_t str_size);
int		find_newline(char *lst, t_fopen *fopen);
char	*insert_newline(char **lst);
void	read_line(int fd, char	**lst);
void	free_lst(char **lst);

#endif
