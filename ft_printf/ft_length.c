/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:05:10 by erho              #+#    #+#             */
/*   Updated: 2023/11/08 14:53:24 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_nbrlen_base(unsigned long long n, int base_nb)
{
	size_t	cnt;

	cnt = n == 0;
	while (n)
	{
		n /= base_nb;
		cnt++;
	}
	return (cnt);
}
