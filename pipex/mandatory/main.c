/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:41:37 by erho              #+#    #+#             */
/*   Updated: 2024/01/30 14:28:05 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipe_loop(t_multi *m, t_pipe *p)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		print_stderror(errno, NULL);
	pid = fork();
	if (pid < 0)
		print_stderror(errno, NULL);
	if (pid == 0)
		child(m, p, fd);
	else
	{
		if (m->cmd_seq == m->last_seq)
			m->last_pid = pid;
		parent(fd);
	}
}

void	run_pipe(t_multi *m, t_pipe *p)
{
	pid_t	temp_pid;
	int		temp;
	int		status;

	temp = m->cmd_seq;
	while (m->cmd_seq <= m->last_seq)
	{
		pipe_loop(m, p);
		m->cmd_seq++;
	}
	while (temp <= m->last_seq)
	{
		temp_pid = waitpid(-1, &status, 0);
		if (temp_pid < 0)
			print_stderror(errno, NULL);
		if (temp_pid == m->last_pid)
			m->last_status = status;
		temp++;
	}
	exit(WEXITSTATUS(m->last_status));
}

int	main(int argc, char **argv, char **envp)
{
	t_multi	*m;
	t_pipe	*p;

	if (argc != 5)
		print_error(STANDARDINPUT);
	m = create_multi(argc);
	p = create_pipe(argc, argv, envp);
	run_pipe(m, p);
	return (0);
}
