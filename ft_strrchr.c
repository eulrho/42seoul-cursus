/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:32:51 by erho              #+#    #+#             */
/*   Updated: 2023/10/07 14:03:09 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str) + 2;
	res = NULL;
	while (--len)
	{
		if (res == NULL && str[len - 1] == (char)c)
			res = &((char *)str)[len - 1];
	}
	return (res);
}
