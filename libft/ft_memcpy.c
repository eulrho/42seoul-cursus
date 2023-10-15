/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:03:16 by erho              #+#    #+#             */
/*   Updated: 2023/10/07 13:16:20 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*u_dest;
	const unsigned char	*u_src;

	if (dest == src)
		return (dest);
	u_dest = (unsigned char *)dest;
	u_src = (const unsigned char *)src;
	i = 0;
	while (i < len)
	{
		u_dest[i] = u_src[i];
		i++;
	}
	return (dest);
}
