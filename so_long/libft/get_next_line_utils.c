/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:14:36 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 14:39:24 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strndup(char *str, int len)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		print_error(MEMORY);
	i = 0;
	while (str[i] && i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlcat(char *dest, char *src, size_t len)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (dest && dest[dest_len])
		dest_len++;
	dest += dest_len;
	while (src[src_len])
		src_len++;
	if (len <= dest_len)
		return (len + src_len);
	while (src[i] && dest_len + i + 1 < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

char	*ft_strjoin(char **s1, t_fopen fopen)
{
	char	*res;
	size_t	len;
	size_t	s1_len;

	len = 0;
	while ((*s1)[len])
		len++;
	s1_len = len;
	len += (size_t)fopen.read_size;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		print_error(MEMORY);
	res[0] = '\0';
	ft_strlcat(res, *s1, s1_len + 1);
	ft_strlcat(res, fopen.buff, len + 1);
	free(*s1);
	return (res);
}
