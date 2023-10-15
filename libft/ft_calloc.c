/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:16:16 by erho              #+#    #+#             */
/*   Updated: 2023/10/12 17:52:14 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	if (size && n > ((size_t) -1) / size)
		return (NULL);
	res = malloc(size * n);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, size * n);
	return (res);
}
