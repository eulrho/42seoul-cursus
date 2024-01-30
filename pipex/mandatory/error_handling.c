/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:51:33 by erho              #+#    #+#             */
/*   Updated: 2024/01/24 21:30:16 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_file_name(char *file_name)
{
	ft_putstr_fd("pipex: ", 2);
	if (file_name != NULL)
	{
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(": ", 2);
	}
}

void	print_stderror(int error_no, char *file_name)
{
	print_file_name(file_name);
	if (error_no == NOTFOUND)
	{
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	else if (error_no == PERMISSION)
	{
		ft_putstr_fd("permission denied\n", 2);
		exit(126);
	}
	else if (error_no == NOSUCH)
	{
		ft_putstr_fd("no such file or directory\n", 2);
		exit(127);
	}
	else
	{
		perror("");
		exit(1);
	}
}

void	print_error(int error_no)
{
	if (error_no == STANDARDINPUT)
	{
		ft_putstr_fd("pipex: invalid standard input\n", 2);
		exit(1);
	}
	else if (error_no == NULLGUARD)
	{
		ft_putstr_fd("pipex: memory allocation failed\n", 2);
		exit(1);
	}
}
