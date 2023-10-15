/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:29:54 by erho              #+#    #+#             */
/*   Updated: 2023/10/07 13:57:00 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	const unsigned char	*c_str;
	size_t				i;

	i = 0;
	c_str = (const unsigned char *)str;
	while (i < len)
	{
		if (c_str[i] == (unsigned char)c)
			return (&((char *)c_str)[i]);
		i++;
	}
	return (NULL);
}
