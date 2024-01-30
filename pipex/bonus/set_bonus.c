/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:25:23 by erho              #+#    #+#             */
/*   Updated: 2024/01/30 13:40:11 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	get_infile_fd(t_multi *m, t_pipe *p)
{
	if (!m->is_here_doc)
	{
		m->infile_fd = open(p->argv[1], O_RDONLY);
		if (m->infile_fd < 0)
			m->open_success = non_exit_print_error(p->argv[1]);
	}
	else
	{
		m->open_success = here_doc(m);
		if (m->open_success != -1)
			m->infile_fd = m->open_success;
		else if (access(m->temp_file, F_OK) == 0)
		{
			if (unlink(m->temp_file) < 0)
				non_exit_print_error(NULL);
		}
	}
}

void	get_outfile_fd(t_multi *m, t_pipe *p)
{
	if (m->is_here_doc)
	{
		m->outfile_fd = open(p->argv[p->argc - 1], O_WRONLY | O_CREAT
				| O_APPEND, 0644);
		if (m->outfile_fd < 0)
			print_stderror(OPEN, p->argv[p->argc - 1]);
	}
	else
	{
		m->outfile_fd = open(p->argv[p->argc - 1], O_WRONLY | O_CREAT
				| O_TRUNC, 0644);
		if (m->outfile_fd < 0)
			print_stderror(OPEN, p->argv[p->argc - 1]);
	}
}

t_multi	*create_multi(int argc, char **argv, int is_here_doc)
{
	t_multi	*result;

	result = (t_multi *)malloc(sizeof(t_multi));
	if (result == NULL)
		print_error(NULLGUARD);
	result->is_here_doc = is_here_doc;
	result->last_seq = argc - 2;
	if (is_here_doc)
	{
		result->limiter = argv[2];
		result->cmd_seq = 3;
		result->temp_file = ".temp";
	}
	else
		result->cmd_seq = 2;
	result->first_seq = result->cmd_seq;
	result->last_pid = 0;
	result->open_success = 1;
	return (result);
}

t_pipe	*create_pipe(int argc, char **argv, char **envp)
{
	t_pipe	*result;

	result = (t_pipe *)malloc(sizeof(t_pipe));
	if (result == NULL)
		print_error(NULLGUARD);
	result->argc = argc;
	result->argv = argv;
	result->envp = envp;
	result->path = find_path(envp);
	return (result);
}
