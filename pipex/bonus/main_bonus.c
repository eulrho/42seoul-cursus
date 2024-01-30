/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:41:37 by erho              #+#    #+#             */
/*   Updated: 2024/01/30 14:28:04 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

	temp = m->first_seq;
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

int	check_input(int argc, char **argv)
{
	int	res;

	if (argc >= 6 && ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		res = 1;
	else
	{
		res = 0;
		if (argc < 5)
			print_error(STANDARDINPUT);
	}
	return (res);
}

int	main(int argc, char **argv, char **envp)
{
	t_multi	*m;
	t_pipe	*p;

	m = create_multi(argc, argv, check_input(argc, argv));
	p = create_pipe(argc, argv, envp);
	get_infile_fd(m, p);
	run_pipe(m, p);
	return (0);
}
