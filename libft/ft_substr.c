/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:43:25 by erho              #+#    #+#             */
/*   Updated: 2023/10/09 12:33:27 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_chr(char *dest, char const *src, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i + start] && i < len)
	{
		dest[i] = src[i + start];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (ft_strlen(s) <= (size_t)start)
	{
		res = (char *)malloc(1);
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	fill_chr(res, s, (size_t)start, len);
	return (res);
}
