/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:34:16 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 14:39:05 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_two_dim_len(char **str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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
