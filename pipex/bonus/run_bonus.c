/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:45:33 by erho              #+#    #+#             */
/*   Updated: 2024/01/30 14:01:37 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	find_access_point(char *file_name)
{
	if (access(file_name, F_OK) == 0)
	{
		if (access(file_name, X_OK) == 0)
			return (0);
		else
			print_stderror(PERMISSION, file_name);
	}
	return (-1);
}

int	find_slash(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
	{
		if (file_name[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*check_access(char **path, char *file_name)
{
	char	*result;
	char	*temp;
	int		i;

	i = 0;
	if (find_slash(file_name))
	{
		if (access(file_name, F_OK) != 0)
			print_stderror(errno, file_name);
		if (access(file_name, X_OK) != 0)
			print_stderror(errno, file_name);
		return (file_name);
	}
	while (path[i])
	{
		temp = ft_strjoin("/", file_name);
		result = ft_strjoin(path[i], temp);
		if (find_access_point(result) == 0)
			return (result);
		free(result);
		free(temp);
		i++;
	}
	print_stderror(NOTFOUND, file_name);
	return (file_name);
}

void	parent(int *fd)
{
	close(fd[1]);
	if (dup2(fd[0], 0) < 0)
		print_stderror(errno, NULL);
	close(fd[0]);
}

void	child(t_multi *m, t_pipe *p, int *fd)
{
	char	*command;
	char	**splited_cmd;

	close(fd[0]);
	if (dup2(fd[1], 1) < 0)
		print_stderror(errno, NULL);
	if (m->cmd_seq == m->first_seq)
		read_file(m);
	else if (m->cmd_seq == m->last_seq)
		write_file(m, p);
	close(fd[1]);
	splited_cmd = parsing_command(p->argv[m->cmd_seq], ' ');
	command = check_access(p->path, splited_cmd[0]);
	if (execve(command, splited_cmd, p->envp) < 0)
		print_stderror(errno, command);
}
