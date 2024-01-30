/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:27:20 by erho              #+#    #+#             */
/*   Updated: 2024/01/24 21:47:34 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# define DEFALUT "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local\
/munki:/Library/Apple/usr/bin"
# define STANDARDINPUT 50
# define NULLGUARD 51
# define NOTFOUND 52
# define PERMISSION 13
# define NOSUCH 2
# define OPEN 54

typedef struct s_command
{
	int		word;
	int		hor_idx;
	int		ver_idx;
	char	quotes;
	int		word_count;
	int		len;
}	t_command;

typedef struct s_pipe
{
	char	**argv;
	char	**envp;
	char	**path;
	int		argc;
}	t_pipe;

typedef struct s_multi
{
	int		cmd_seq;
	int		infile_fd;
	int		outfile_fd;
	char	*limiter;
	char	*temp_file;
	int		first_seq;
	int		last_seq;
	pid_t	last_pid;
	int		last_status;
}	t_multi;

// error
void	print_error(int error_no);
void	print_stderror(int error_no, char *file_name);

// run
void	child(t_multi *m, t_pipe *p, int *fd);
void	parent(int *fd);
char	*check_access(char **path, char *file_name);
int		find_access_point(char *file_name);
int		find_slash(char *file_name);

// parse
int		check_quote(char *s, int front);
int		check_slash(char *s, int target);
int		is_with_slash(char *s, int target);
int		is_quote(char *s, int target);
char	**parsing_command(char *s, char c);

// utils
char	**find_basic_path(void);
char	**find_path(char **envp);
void	read_file(t_multi *m, t_pipe *p);
void	write_file(t_multi *m, t_pipe *p);

// set
t_multi	*create_multi(int argc);
t_pipe	*create_pipe(int argc, char **argv, char **envp);
void	get_infile_fd(t_multi *m, t_pipe *p);
void	get_outfile_fd(t_multi *m, t_pipe *p);

#endif
