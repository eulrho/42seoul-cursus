/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:11:06 by erho              #+#    #+#             */
/*   Updated: 2024/01/30 13:41:32 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	standard_input(int fd_temp, char *limiter)
{
	size_t	len;
	char	*line;

	len = ft_strlen(limiter);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, len) == 0)
		{
			if (line[len] == '\n' && line[len + 1] == '\0')
			{
				free(line);
				close(fd_temp);
				break ;
			}
		}
		ft_putstr_fd(line, fd_temp);
		free(line);
	}
	return (1);
}

int	write_temp_file(char *temp_file, char *limiter)
{
	int		fd_temp;

	fd_temp = open(temp_file, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd_temp < 0)
		return (non_exit_print_error(temp_file));
	else
		return (standard_input(fd_temp, limiter));
}

int	here_doc(t_multi *m)
{
	int		fd_temp;

	if (write_temp_file(m->temp_file, m->limiter))
	{
		fd_temp = open(m->temp_file, O_RDONLY);
		if (fd_temp < 0)
			return (non_exit_print_error(m->temp_file));
		else
			return (fd_temp);
	}
	return (-1);
}
