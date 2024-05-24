/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:11:14 by erho              #+#    #+#             */
/*   Updated: 2024/02/20 16:22:36 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_usleep(int time)
{
	ssize_t	usleep_time;

	usleep_time = get_time() + (ssize_t)time;
	while (usleep_time > get_time())
		usleep(100);
}
