/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:42:22 by erho              #+#    #+#             */
/*   Updated: 2024/01/30 13:57:51 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	**find_basic_path(void)
{
	char	*target;
	char	**result;

	target = ft_strdup(DEFALUT);
	result = ft_split(target, ':');
	free(target);
	return (result);
}

char	**find_path(char **envp)
{
	char	*target;
	char	**result;
	int		i;

	i = 0;
	if (envp == NULL)
		return (find_basic_path());
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (!envp[i])
		return (find_basic_path());
	target = ft_strdup(envp[i] + 5);
	result = ft_split(target, ':');
	free(target);
	return (result);
}

void	read_file(t_multi *m)
{
	if (m->open_success == -1)
		exit(1);
	if (m->is_here_doc)
	{
		if (dup2(m->infile_fd, 0) < 0)
			print_stderror(errno, NULL);
		close(m->infile_fd);
		if (unlink(m->temp_file) < 0)
			print_stderror(errno, NULL);
	}
	else
	{
		if (dup2(m->infile_fd, 0) < 0)
			print_stderror(errno, NULL);
		close(m->infile_fd);
	}
}

void	write_file(t_multi *m, t_pipe *p)
{
	get_outfile_fd(m, p);
	if (dup2(m->outfile_fd, 1) < 0)
		print_stderror(errno, NULL);
	close(m->outfile_fd);
}
