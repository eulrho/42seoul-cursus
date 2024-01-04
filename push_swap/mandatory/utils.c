/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:31:36 by erho              #+#    #+#             */
/*   Updated: 2023/12/26 19:59:10 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

int	push_swap_atoi(const char *str)
{
	int			minus;
	long long	res;

	minus = 1;
	res = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	if (*str == '\0')
		print_error();
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (minus * res > INT_MAX || minus * res < INT_MIN)
			print_error();
		str++;
	}
	if (*str != '\0')
		print_error();
	return (minus * (int)res);
}
