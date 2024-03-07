/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_isnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:36:57 by erho              #+#    #+#             */
/*   Updated: 2024/03/05 19:51:16 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	philo_isdisit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	else
		return (FALSE);
}

int	philo_isnum(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (philo_isdisit(str[idx]) == FALSE)
			return (FALSE);
		idx++;
	}
	return (TRUE);
}
