/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:07:46 by erho              #+#    #+#             */
/*   Updated: 2023/10/28 15:23:37 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*move_address(char **lst, size_t str_size)
{
	char	*res;
	size_t	lst_len;

	lst_len = 0;
	while ((*lst)[lst_len])
		lst_len++;
	res = ft_strndup(&(*lst)[str_size], lst_len - str_size);
	free(*lst);
	return (res);
}

int	find_newline(char *lst, t_fopen *fopen)
{
	int	i;

	i = 0;
	while (lst[i] && lst[i] != '\n')
		i++;
	if (lst[i] == '\n')
	{
		i++;
		fopen->is_newline = 1;
	}
	else
		fopen->is_newline = 0;
	return (i);
}

char	*insert_newline(char **lst)
{
	char	*res;
	t_fopen	fopen;

	fopen.str_size = find_newline(*lst, &fopen);
	res = ft_strndup(*lst, fopen.str_size);
	if (res == NULL)
		fopen.is_newline = 0;
	if (fopen.is_newline == 1)
		*lst = move_address(lst, fopen.str_size);
	else
	{
		free(*lst);
		*lst = NULL;
	}
	return (res);
}

void	read_line(int fd, char	**lst)
{
	t_fopen	fopen;

	fopen.is_newline = 0;
	fopen.buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (fopen.is_newline != 1)
	{
		fopen.read_size = read(fd, fopen.buff, BUFFER_SIZE);
		if (fopen.read_size <= 0)
		{
			if (!(fopen.read_size == 0 && (*lst)[0] != '\0'))
			{
				free(*lst);
				*lst = NULL;
			}
			break ;
		}
		fopen.buff[fopen.read_size] = '\0';
		*lst = ft_strjoin(lst, fopen);
		if (*lst == NULL)
			break ;
		find_newline(*lst, &fopen);
	}
	free(fopen.buff);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*lst[OPEN_MAX + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (lst[fd] == NULL)
	{
		lst[fd] = (char *)malloc(sizeof(char) * (1));
		if (lst[fd] == NULL)
			return (NULL);
		lst[fd][0] = '\0';
	}
	read_line(fd, &(lst[fd]));
	if (lst[fd] == NULL)
		return (NULL);
	res = insert_newline(&(lst[fd]));
	return (res);
}
