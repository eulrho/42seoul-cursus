/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:06:33 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 18:34:07 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid_file_name(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (FILE_NAME);
	if (file[len - 4] != '.')
		return (FILE_NAME);
	if (file[len - 3] != 'b')
		return (FILE_NAME);
	if (file[len - 2] != 'e')
		return (FILE_NAME);
	if (file[len - 1] != 'r')
		return (FILE_NAME);
	return (VALID);
}

void	is_valid_file(char *file, int fd)
{
	if (fd < 0)
		print_error(INVALID_FILE);
	if (is_valid_file_name(file) == FILE_NAME)
		print_error(FILE_NAME);
}
