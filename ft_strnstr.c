/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:19:06 by erho              #+#    #+#             */
/*   Updated: 2023/10/10 20:19:24 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char *)s1);
	if (len == 0)
		return (NULL);
	while (s1[i] && i < len)
	{
		if (i + s2_len > len)
			break ;
		if (s1[i] == *s2)
		{
			if (ft_strncmp(&s1[i], s2, s2_len) == 0)
				return (&((char *)s1)[i]);
		}
		i++;
	}
	return (NULL);
}
