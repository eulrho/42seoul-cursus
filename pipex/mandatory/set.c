/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:25:23 by erho              #+#    #+#             */
/*   Updated: 2024/01/30 13:41:53 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_infile_fd(t_multi *m, t_pipe *p)
{
	m->infile_fd = open(p->argv[1], O_RDONLY);
	if (m->infile_fd < 0)
		print_stderror(OPEN, p->argv[1]);
}

void	get_outfile_fd(t_multi *m, t_pipe *p)
{
	m->outfile_fd = open(p->argv[p->argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (m->outfile_fd < 0)
		print_stderror(OPEN, p->argv[p->argc - 1]);
}

t_multi	*create_multi(int argc)
{
	t_multi	*result;

	result = (t_multi *)malloc(sizeof(t_multi));
	if (result == NULL)
		print_error(NULLGUARD);
	result->last_seq = argc - 2;
	result->cmd_seq = 2;
	result->first_seq = result->cmd_seq;
	result->last_pid = 0;
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
