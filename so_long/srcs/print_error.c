/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:26:50 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 18:44:40 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	print_error(int error_no)
{
	ft_putstr_fd("Error\n", 2);
	if (error_no == OTHER_CHARACTERS)
		ft_putstr_fd("other characters on the map", 2);
	else if (error_no == MEMORY)
		ft_putstr_fd("memory error", 2);
	else if (error_no == FILE_NAME)
		ft_putstr_fd("invalid file name", 2);
	else if (error_no == STANDARD_INPUT)
		ft_putstr_fd("invalid input", 2);
	else if (error_no == INVALID_FILE)
		ft_putstr_fd("file is empty or not found", 2);
	else if (error_no == INVALID_MAP)
		ft_putstr_fd("invalid configuration on map", 2);
	else if (error_no == INVALID_PATH)
		ft_putstr_fd("path not found", 2);
	else if (error_no == MAP_SIZE)
		ft_putstr_fd("map is not rectangle", 2);
	else if (error_no == OVER_FLOW)
		ft_putstr_fd("overflow!!!!!!!!!", 2);
	exit(1);
}
