/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:02:38 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 18:45:40 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)dest;
	i = 0;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (dest);
}

void	ft_bzero(void *str, size_t len)
{
	ft_memset(str, 0, len);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	if (size && n > ((size_t) -1) / size)
		print_error(OVER_FLOW);
	res = malloc(size * n);
	if (res == NULL)
		print_error(MEMORY);
	ft_bzero(res, size * n);
	return (res);
}
