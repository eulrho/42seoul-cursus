/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:45 by erho              #+#    #+#             */
/*   Updated: 2023/10/07 14:48:58 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	case_common(size_t len, unsigned char *dest, const unsigned char *src)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	case_overlap(size_t len, unsigned char *dest, const unsigned char *src)
{
	size_t	i;

	i = len - 1;
	while (1)
	{
		dest[i] = src[i];
		if (i == 0)
			break ;
		else
			i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*uc_dest;
	const unsigned char	*uc_src;

	uc_dest = (unsigned char *)dest;
	uc_src = (const unsigned char *)src;
	if (len == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	if (uc_dest < uc_src)
		case_common(len, uc_dest, uc_src);
	else
		case_overlap(len, uc_dest, uc_src);
	return (dest);
}
