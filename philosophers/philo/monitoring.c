/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:24:17 by erho              #+#    #+#             */
/*   Updated: 2024/03/05 18:45:19 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	die_philo(t_monitor *monitor)
{
	pthread_mutex_lock(&monitor->mutex->end);
	monitor->is_exit = TRUE;
	pthread_mutex_unlock(&monitor->mutex->end);
	return (TRUE);
}

int	end_of_meal(t_monitor *monitor, int i)
{
	int	check_count;

	pthread_mutex_lock(&monitor->mutex->end);
	if (monitor->thread[i].count_eating == monitor->argument->n_eating)
		check_count = TRUE;
	else
		check_count = FALSE;
	pthread_mutex_unlock(&monitor->mutex->end);
	if (check_count == TRUE)
	{
		if (monitor->thread[i].is_full == FALSE)
		{
			monitor->count_ending += 1;
			monitor->thread[i].is_full = TRUE;
		}
	}
	if (monitor->count_ending != monitor->argument->n_philo)
		return (FALSE);
	return (die_philo(monitor));
}

int	check_dead_time(t_monitor *monitor, int i)
{
	ssize_t	temp;

	pthread_mutex_lock(&monitor->mutex->time);
	temp = get_time() - monitor->thread[i].eat_time;
	pthread_mutex_unlock(&monitor->mutex->time);
	if (temp > (ssize_t)monitor->argument->time_to_die)
		return (TRUE);
	return (FALSE);
}

int	check_death(t_monitor *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->argument->n_philo)
	{
		if (end_of_meal(monitor, i) == TRUE)
			return (TRUE);
		if (check_dead_time(monitor, i) == TRUE)
		{
			print_result(&monitor->thread[i], DEAD);
			return (die_philo(monitor));
		}
		i++;
	}
	return (FALSE);
}

void	*monitor_routine(void *arg)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)arg;
	while (1)
	{
		if (check_death(monitor) == TRUE)
			break ;
	}
	return (arg);
}
